<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);

$servername = "localhost";
$username = "root";
$password = "123qaz";
$dbname = "Freelance";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

if (isset($_GET['action']) && $_GET['action'] == 'delete' && isset($_GET['id'])) {
    $project_id = $_GET['id'];
    $stmt = $conn->prepare("DELETE FROM projects WHERE id = ?");
    $stmt->bind_param("i", $project_id);

    if ($stmt->execute()) {
        // Redirect back to the main admin page or display a success message
        header("Location: index.php");
        exit();
    } else {
        echo "Error deleting project: " . $conn->error;
    }

    $stmt->close();
}

function listProjects() {
    global $conn; // Use the global connection
    $sql = "SELECT id, client_name, title, description, image FROM projects";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        while($row = $result->fetch_assoc()) {
            echo "<tr>";
            echo "<td>" . htmlspecialchars($row["id"]) . "</td>";
            echo "<td>" . htmlspecialchars($row["client_name"]) . "</td>";
            echo "<td>" . htmlspecialchars($row["title"]) . "</td>";
            echo "<td>" . htmlspecialchars($row["description"]) . "</td>";
            echo "<td>" . htmlspecialchars($row["image"]) . "</td>";
            echo "<td><a href='edit_project.php?id=" . $row["id"] . "'>Edit</a> | <a href='process_projects.php?action=delete&id=" . $row["id"] . "' onclick='return confirm(\"Are you sure?\")'>Delete</a></td>";
            echo "</tr>";
        }
    } else {
        echo "<tr><td colspan='5'>No projects found</td></tr>";
    }
}

// Handle project addition
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['action']) && $_POST['action'] == 'add') {
    // Retrieve form data
    $clientName = $conn->real_escape_string($_POST['client_name']);
    $title = $conn->real_escape_string($_POST['title']);
    $description = $conn->real_escape_string($_POST['description']);

    // File upload parameters
    $fileName = $_FILES["image"]["name"];
    $fileTmpName = $_FILES["image"]["tmp_name"];
    $fileSize = $_FILES["image"]["size"];
    $fileType = $_FILES["image"]["type"];
    $extension = strtolower(pathinfo($fileName, PATHINFO_EXTENSION));

    // Allowed extensions and MIME types
    $allowedExtensions = ['jpg', 'jpeg', 'png', 'gif'];
    $allowedMimeTypes = ['image/jpeg', 'image/png', 'image/gif'];
    $maxFileSize = 5 * 1024 * 1024; // 5 MB

    // Initialize upload OK flag
    $uploadOk = 1;

    // Check if image file is an actual image
    if (isset($_FILES["image"])) {
        $check = getimagesize($fileTmpName);
        if ($check !== false) {
            if ($fileSize > $maxFileSize) {
                echo "Error: File size is too large. Maximum size allowed is 5MB.";
                $uploadOk = 0;
            } elseif (!in_array($extension, $allowedExtensions) || !in_array($fileType, $allowedMimeTypes)) {
                echo "Error: Invalid file extension or MIME type.";
                $uploadOk = 0;
            } else {
                // Sanitize and prepare the file name
                $originalName = pathinfo($fileName, PATHINFO_FILENAME);
                $extension = pathinfo($fileName, PATHINFO_EXTENSION);
                $sanitizeFileName = preg_replace('/[^a-zA-Z0-9_-]/', '_', $originalName);
                $safeFileName = uniqid() . '_' . $sanitizeFileName . '_' . $extension;

                $targetDirectory = "/opt/lampp/htdocs/freelancer/images/";
                $targetFile = $targetDirectory . $safeFileName;
                $relativePath = "images/" . $safeFileName;
                if (!move_uploaded_file($fileTmpName, $targetFile)) {
                    echo "Sorry, there was an error uploading your file.";
                    $uploadOk = 0;
                }
            }
        } else {
            echo "File is not an image.";
            $uploadOk = 0;
        }
    } else {
        echo "No file was uploaded.";
        $uploadOk = 0;
    }

    if ($uploadOk) {
        // Prepare and bind
        $stmt = $conn->prepare("INSERT INTO projects (client_name, title, description, image) VALUES (?, ?, ?, ?)");
        $stmt->bind_param("ssss", $clientName, $title, $description, $relativePath);
        // Execute and redirect or error
        if ($stmt->execute()) {
            // Optionally, redirect to the admin dashboard
            header('Location: index.php');
            exit();
        } else {
            echo "Error: " . $stmt->error;
        }
        $stmt->close();
    }
}
?>