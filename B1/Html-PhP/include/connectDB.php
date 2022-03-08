<?php
    $con = mysqli_connect("localhost", "root", "", "dossier_juin_2020");
    mysqli_query($con, "SET NAMES UTF8");

    if(mysqli_connect_errno()) {
        printf("Échec de la connexion : %s\n", mysqli_connect_error());
        exit();
    }
?>