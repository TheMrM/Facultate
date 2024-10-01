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


error_reporting(E_ALL);
ini_set('display_errors', 1);

require_once 'db_connection.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = $_POST['username'] ?? '';
    $password = $_POST['password'] ?? '';
    $action = $_POST['action'] ?? '';

    if ($action == 'Register') {
        $hashedPassword = password_hash($password, PASSWORD_DEFAULT);

        // Insert new user into the database
        $sql = "INSERT INTO users (username, password) VALUES (?, ?)";
        if ($stmt = $conn->prepare($sql)) {
            $stmt->bind_param("ss", $username, $hashedPassword);
            if ($stmt->execute()) {
                echo "User registered successfully.";
                header("Location: login.php");
                exit;
            } else {
                echo "Error: " . $stmt->error;
            }
            $stmt->close();
        }
    } elseif ($action == 'Login') {
        $sql = "SELECT id, username, password, role FROM users WHERE username = ?";
        if ($stmt = $conn->prepare($sql)) {
            $stmt->bind_param("s", $username);
            $stmt->execute();
            $stmt->store_result();

            // Check if username exists, if yes then verify password
            if ($stmt->num_rows == 1) {
                $stmt->bind_result($id, $fetchUsername, $hashedPassword, $role);
                if ($stmt->fetch() && password_verify($password, $hashedPassword)) {
                    session_regenerate_id(); // Regenerate session ID
                    $_SESSION['loggedin'] = true;
                    $_SESSION['id'] = $id;
                    $_SESSION['username'] = $username;
                    $_SESSION['role'] = $role;
                    $_SESSION['last_activity'] = time();

                    // Redirect user to dashboard if admin
                    if ($role == 'admin') {
                        header("location: index.php");
                    } else {
                        header("location: ../index.php");
                    }
                    exit;
                } else {
                    echo "Invalid username or password.";
                }
            } else {
                echo "Invalid username or password.";
            }
            $stmt->close();
        }
    }
    $conn->close();
}
?>
