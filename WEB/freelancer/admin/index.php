<?php
session_start();

// Check if the last activity is set, and if it's been more than 10 minutes
if (isset($_SESSION['last_activity']) && (time() - $_SESSION['last_activity'] > 600)) {
    // Last request was more than 600 seconds ago (10 minutes)
    session_unset();     // unset $_SESSION variable
    session_destroy();   // destroy session data
    header("Location: login.html"); // redirect to login page
    exit;
}

$_SESSION['last_activity'] = time(); // update last activity time stamp

// Check user login status and role
if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true || $_SESSION['role'] !== 'admin') {
    header('Location: login.php');
    exit;
}

// First time login alert
if (!isset($_SESSION['first_time'])) {
    $_SESSION['first_time'] = false;
    $firstTime = true;
} else {
    $firstTime = false;
}

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Admin Panel</title>

    <script>
    document.addEventListener("DOMContentLoaded", function() {
        <?php if ($firstTime): ?>
            alert("Note: For security reasons, you will be automatically logged out after 10 minutes of inactivity.");
        <?php endif; ?>

        setTimeout(function() {
            alert("You will be logged out in 30 seconds due to inactivity.");
            // Optionally, make an AJAX call to refresh the session or direct logout
            setTimeout(function() {
                window.location.href = 'logout.php'; // Redirect to the logout script
            }, 30000); // 30 seconds grace period
        }, 570000); // 570000 milliseconds = 9.5 minutes
    });
    </script>

</head>
<body>
    <h1>Administrator Panel</h1>
    <p>Welcome, <?php echo $_SESSION['username']; ?>! <a href="logout.php">Logout</a></p>
    <!-- Add Services Section -->
    <h2>Add Services</h2>
    <form action="process_services.php" method="post" enctype="multipart/form-data">
        <input type="hidden" name="action" value="add">
        Title: <input type="text" name="title"><br>
        Description: <textarea name="description"></textarea><br>
        Image: <input type="file" name="image" required><br>
        <input type="submit" value="Add Service">
    </form>

    <h2>Current Services</h2>
    <table>
        <tr>
            <th>ID</th>
            <th>Title</th>
            <th>Image Location</th>
            <th>Description</th>
            <th>Actions</th>
        </tr>
        <?php
        include 'process_services.php';
        listServices(); // Adjusted to call listServices() instead
        ?>
    </table>

    <!-- Add Projects Section -->
    <h2>Add Project</h2>
    <form action="process_projects.php" method="post" enctype="multipart/form-data">
        <input type="hidden" name="action" value="add">
        Client Name: <input type="text" name="client_name"><br>
        Title: <input type="text" name="title"><br>
        Description: <textarea name="description"></textarea><br>
        Image: <input type="file" name="image" required><br>
        <input type="submit" value="Add Project">
    </form>

    <h2>Current Projects</h2>
    <table>
        <tr>
            <th>ID</th>
            <th>Client Name</th>
            <th>Service</th>
            <th>Service description</th>
            <th>Image Location</th>
            <th>Actions</th>
        </tr>
        <?php
        include 'process_projects.php';
        listProjects();
        ?>
    </table>

<script>
setTimeout(function() {
    alert("You will be logged out due to inactivity. Please save your work.");
    // Optionally, make an AJAX call to refresh the session or direct logout
    window.location.href = 'logout.php'; // Redirect to a logout script
}, 570000); // 570000 milliseconds = 9.5 minutes
</script>

</body>
</html>
