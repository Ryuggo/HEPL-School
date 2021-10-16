<?php
    include("php/connectDB.php");


    //$json = urldecode($_POST["json"]);
    //$fileName = urldecode($_POST["name"]);

    $request = $_POST["request"];
    
    $dbresult = mysqli_query($mysqli, $request);
?>