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
    $sql = "SELECT id, client_name, title, description FROM projects";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        while($row = $result->fetch_assoc()) {
            echo "<tr>";
            echo "<td>" . $row["id"] . "</td>";
            echo "<td>" . htmlspecialchars($row["client_name"]) . "</td>";
            echo "<td>" . htmlspecialchars($row["title"]) . "</td>";
            echo "<td>" . htmlspecialchars($row["description"]) . "</td>";
            echo "<td><a href='edit.php?id=" . $row["id"] . "'>Edit</a> | <a href='process.php?action=delete&id=" . $row["id"] . "' onclick='return confirm(\"Are you sure?\")'>Delete</a></td>";
            echo "</tr>";
        }
    } else {
        echo "<tr><td colspan='5'>No projects found</td></tr>";
    }
}

?>