<?php
// Database parameters
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
?>