<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Admin Panel - Manage Projects</title>
</head>
<body>
    <h1>Project Management</h1>

    <h2>Add Project</h2>
    <form action="process.php" method="post">
        <input type="hidden" name="action" value="add">
        Client Name: <input type="text" name="client_name"><br>
        Title: <input type="text" name="title"><br>
        Description: <textarea name="description"></textarea><br>
        <input type="submit" value="Add Project">
    </form>

    <h2>Current Projects</h2>
    <table>
        <tr>
            <th>ID</th>
            <th>Client Name</th>
            <th>Title</th>
            <th>Description</th>
            <th>Actions</th>
        </tr>
        <?php
        include 'process.php';
        echo listProjects();
        ?>
    </table>
</body>
</html>