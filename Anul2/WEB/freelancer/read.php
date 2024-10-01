<?php

$conn = new mysqli("localhost", "root", "123qaz", "Freelance");

if($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT id, client_name, title, description FROM projects";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    while($row = $result->fetch_assoc()) {
        // Correct the column names based on your query
        echo "id: " . $row["id"]. " - Client Name: " . $row["client_name"]. " - Title: " . $row["title"]. " - Description: " . substr($row["description"], 0, 50) . "...<br>";
    }
} else {
    echo "0 results";
}
$conn->close();
