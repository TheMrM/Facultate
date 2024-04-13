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

// Handle service deletion
if (isset($_GET['action']) && $_GET['action'] == 'delete' && isset($_GET['id'])) {
    $service_id = $_GET['id'];
    $stmt = $conn->prepare("DELETE FROM services WHERE id = ?");
    $stmt->bind_param("i", $service_id);

    if ($stmt->execute()) {
        // Redirect back to the main admin page or display a success message
        header("Location: index.php");
        exit();
    } else {
        echo "Error deleting service: " . $conn->error;
    }

    $stmt->close();
}

// List all services
function listServices() {
    global $conn; // Use the global connection
    $sql = "SELECT id, title, image, description FROM services";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        while($row = $result->fetch_assoc()) {
            echo "<tr>";
            echo "<td>" . htmlspecialchars($row["id"]) . "</td>";
            echo "<td>" . htmlspecialchars($row["title"]) . "</td>";
            echo "<td>" . htmlspecialchars($row["image"]) . "</td>";
            echo "<td>" . htmlspecialchars($row["description"]) . "</td>";
            echo "<td><a href='edit_services.php?id=" . $row["id"] . "'>Edit</a> | <a href='process_services.php?action=delete&id=" . $row["id"] . "' onclick='return confirm(\"Are you sure?\")'>Delete</a></td>";
            echo "</tr>";
        }
    } else {
        echo "<tr><td colspan='5'>No projects found</td></tr>";
    }

}

// Handle service addition
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['action']) && $_POST['action'] == 'add') {
    // Retrieve form data
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
            // Check file size
            if ($fileSize > $maxFileSize) {
                echo "Error: File size is too large. Maximum size allowed is 5MB.";
                $uploadOk = 0;
            }

            // Check file type and extension
            if (!in_array($extension, $allowedExtensions) || !in_array($fileType, $allowedMimeTypes)) {
                echo "Error: Invalid file extension or MIME type.";
                $uploadOk = 0;
            }

            // Move file if all checks are passed
            if ($uploadOk) {
                $sanitizedFileName = preg_replace('/[^a-zA-Z0-9_-]/', '_', basename($fileName));  // Sanitize file name
                $safeFileName = uniqid() . '_' . $sanitizedFileName;  // Prepend unique ID
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

    // Insert into database if file was successfully uploaded
    if ($uploadOk) {
        $stmt = $conn->prepare("INSERT INTO services (title, image, description) VALUES (?, ?, ?)");
        $stmt->bind_param("sss", $title, $relativePath, $description);
        if ($stmt->execute()) {
            echo "New service added successfully.";
            header('Location: index.php');
            exit();
        } else {
            echo "Error: " . $stmt->error;
        }
        $stmt->close();
    }
}
?>
