<?php
    require("./include/header.php");
    require("./include/connectDB.php");
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <title>Gestion de Vins</title>
</head>

<body class="vin">
    <div class="page" style="padding-top:8%;">
        <div class="text-center">
            <a class="btn btn-vin col-md-6" href="bouteille.php" style="margin:40px 0px 40px 0px;">Bouteilles</a>
            </br>
            <a class="btn btn-vin col-md-6" href="producteur.php" style="margin:40px 0px 40px 0px;">Producteurs</a>
            </br>
            <a class="btn btn-vin col-md-6" href="vin.php" style="margin:40px 0px 40px 0px;">Vins</a>
            </br>
        </div>
    </div>

    <?php require("./include/footer.php"); ?>
</body>
</html>