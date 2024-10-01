<?php
$servername = "localhost";
$username = "root";
$password = "123qaz";
$dbname = "Freelance";
$project_id = isset($_GET['id']) ? intval($_GET['id']) : 0;

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Fetch the project's data if the ID is valid
if ($project_id > 0) {
    $stmt = $conn->prepare("SELECT id, client_name, title, description FROM projects WHERE id = ?");
    $stmt->bind_param("i", $project_id);
    $stmt->execute();
    $result = $stmt->get_result();
    $project = $result->fetch_assoc();
    $stmt->close();
}

// Check if the form was submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $project_id = $_POST["id"];
    $client_name = $_POST["client_name"];
    $title = $_POST["title"];
    $description = $_POST["description"];
    $imagePath = $_POST["image"];


    // Update the project
    $stmt = $conn->prepare("UPDATE projects SET client_name = ?, title = ?, description = ?, image = ?, WHERE id = ?");
    $stmt->bind_param("sss", $client_name, $title, $description, $project_id);

    if ($stmt->execute()) {
        echo "Project updated successfully.";
        header("Location: index.php");
    } else {
        echo "Error: " . $stmt->error;
    }
    $stmt->close();
}

$conn->close();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Edit Project</title>
</head>
<body>
    <?php if (isset($project)) : ?>
        <h2>Edit Project "<?php echo $project["title"]; ?>"</h2>
        <form action="edit.php" method="post">
            <input type="hidden" name="id" value="<?php echo $project["id"]; ?>">
            <label for="client_name">Client Name:</label>
            <input type="text" name="client_name" id="client_name" value="<?php echo $project["client_name"]; ?>"><br>
            <label for="title">Title:</label>
            <input type="text" name="title" id="title" value="<?php echo $project["title"]; ?>"><br>
            <label for="description">Description:</label>
            <input type="image" name="image" id="image" value=""><br>
            <label>
            <textarea name="description" id="description"><?php echo $project["description"]; ?></textarea><br>
            <input type="submit" value="Update Project">
        </form>
    <?php else : ?>
        <p>Project not found.</p>
    <?php endif; ?>

    <script>
    setTimeout(function() {
        alert("You will be logged out due to inactivity. Please save your work.");
        // Optionally, make an AJAX call to refresh the session or direct logout
        window.location.href = 'logout.php'; // Redirect to a logout script
    }, 570000); // 570000 milliseconds = 9.5 minutes
    </script>
</body>
</html>
