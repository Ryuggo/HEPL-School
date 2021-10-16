<?php
    require("./include/header.php");
    require("./include/connectDB.php");

    $idBout = htmlspecialchars($_GET["idbout"]);

// Récupération de toutes les infos sur une bouteille
    $request = mysqli_query($con, "SELECT * FROM bouteille WHERE idBouteille LIKE \"$idBout\"");
    $data = mysqli_fetch_array($request);
    $date = $data[1];
    $prix = $data[2];
    $prix /= 100;
    $cont = $data[3];
    $cont /= 10;
    $deg = $data[4];
    $deg /= 10;
    $idVin = $data[5];
    $idEmpl = $data[6];
    $idCons = $data[7];
    $idFourn = $data[8];

    $request = mysqli_query($con, "SELECT * FROM consommation WHERE idConsommation LIKE \"$idCons\"");
    $data = mysqli_fetch_array($request);
    $dateCons = $data[1];
    $noteCons = $data[2];
    $noteCons = ucfirst($noteCons);

    $request = mysqli_query($con, "SELECT * FROM fournisseur WHERE idFournisseur LIKE \"$idFourn\"");
    $data = mysqli_fetch_array($request);
    $nomFourn = $data[1];
    $rueFourn = $data[2];

    $request = mysqli_query($con, "SELECT * FROM vin WHERE idVin LIKE \"$idVin\"");
    $data = mysqli_fetch_array($request);
    $cuvee = ucwords($data[1]);
    $appel = ucwords($data[2]);
    $region = ucwords($data[3]);
    $col = $data[5];
    $idProd = $data[6];
    $garde = $data[7];
    $bio = $data[8];
    $mill = $data[9];
    $pays = $data[4];
    $requesttmp = mysqli_query($con, "SELECT * FROM pays WHERE idPays LIKE \"$pays\"");
    $data = mysqli_fetch_array($requesttmp);
    $paysVin = $data[1];

    $request = mysqli_query($con, "SELECT * FROM producteur WHERE idProducteur LIKE \"$idProd\"");
    $data = mysqli_fetch_array($request);
    $prod = $data[1];
    $rue = $data[2];
    $num = $data[3];
    $cpp = $data[4];
    $loc = $data[5];
    $pays = $data[6];
    $requesttmp = mysqli_query($con, "SELECT * FROM pays WHERE idPays LIKE \"$pays\"");
    $data = mysqli_fetch_array($requesttmp);
    $paysProd = $data[1];
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <title>Gestion de Vins - Bouteilles consommées</title>
</head>

<body class="bout">
    <div class="page text-center">
        <div class="flex-around">
            <div class="btn btn-vin col-md-3">
                <?php
                    echo("Cuvée : ".ucwords($cuvee)."</br>");
                    echo("Appellation : ".ucwords($appel)."</br>");
                    echo("Région : ".ucwords($region)."</br>");
                    echo("Pays : ".$paysVin."</br>");
                    $garde1 = round($garde / 100, 0);
                    $garde2 = $garde % 100;
                    echo("Garde : De ".$garde1." à ".$garde2." ans</br>");
                    if($bio == 1)
                        echo("Bio</br>");
                    else
                        echo("Non Bio</br>");
                    echo("Millésime : ".$mill."</br>");
                    echo("</br>");
                    if($col == "rgt") {
                        ?><img class="img" src="image/rgt.png" /><?php
                    } else if($col == "blt") {
                        ?><img class="img" src="./image/blt.png" /><?php
                    } else if($col == "rst") {
                        ?><img class="img" src="./image/rst.png" /><?php
                    } else if($col == "ble") {
                        ?><img class="img" src="./image/ble.png" /><?php
                    } else if($col == "rse") {
                        ?><img class="img" src="./image/rse.png" /><?php
                    } else if($col == "rgl") {
                        ?><img class="img" src="./image/rgl.png" /><?php
                    } else if($col == "bll") {
                        ?><img class="img" src="./image/bll.png" /><?php
                    }
                ?>
            </div>
            <div class="btn btn-vin col-md-3">
                <?php
                    echo("Date d'achat : ".$date."</br>");
                    echo("Prix : ".$prix."</br>");
                    echo("Contenance : ".$cont."</br>");
                    echo("Degré : ".$deg."</br>");
                    echo("</br>");
                    echo("Fournisseur :</br>".$nomFourn."</br>");
                    echo("Rue du fournisseur :</br>".$rueFourn."</br>");
                    echo("</br>");
                    echo("Date de consommation :</br>".$dateCons."</br>");
                    echo("Note :</br>".$noteCons."</br>");
                ?>
            </div>
            <div class="btn btn-vin col-md-3">
                <?php
                    echo("Nom : ".ucwords($prod)."</br>");
                    echo("Rue :</br>".$rue."</br>");
                    echo("Numéro : ".$num."</br>");
                    echo("Code postal : ".$cpp."</br>");
                    echo("Localité : ".ucwords($loc)."</br>");
                    echo("Pays : ".$paysProd."</br>");
                ?>
            </div>
        </div>
    </div>

    <?php require("./include/footer.php"); ?>
</body>
</html>