<?php
session_start();
// Clear session data
$_SESSION = array();
session_destroy();
// Redirect to login page
header("Location: login.html");
exit;
?>