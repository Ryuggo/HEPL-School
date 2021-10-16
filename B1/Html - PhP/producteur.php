<?php
    require("./include/header.php");
    require("./include/connectDB.php");

// Filtre
    if(isset($_POST["pays"])) {
        $locfiltre = htmlspecialchars($_POST["loc"]);
        $paysfiltre = htmlspecialchars($_POST["pays"]);
        $tri = htmlspecialchars($_POST["tri"]);
        $all = 1;
    } else {
        $locfiltre = "";
        $paysfiltre = "";
        $tri = "";
        $all = 0;
    }
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <title>Gestion de Vins - Producteurs</title>
</head>

<body class="vin">
    <div class="page">
        <form action="" method="post">
            <div class="flex-around">
<!-- Filtre -->
                <div>
                    <h5>Filtrer par :</h5>
                    <div class="flex-around">
                        Pays <input list="pays" name="pays" class="form-control" value="<?php echo($paysfiltre); ?>">
                        <datalist id="pays">
                            <?php
                                $request = mysqli_query($con, "SELECT DISTINCT idPays FROM producteur");
                                $nbre = mysqli_num_rows(mysqli_query($con, "SELECT DISTINCT idPays FROM producteur"));

                                for($i=0; $i < $nbre; $i++)
                                {
                                    $data = mysqli_fetch_array($request);
                                    $pays = $data[0];

                                    $requesttmp = mysqli_query($con, "SELECT * FROM pays WHERE idPays LIKE \"$pays\"");
                                    $data = mysqli_fetch_array($requesttmp);
                                    $pays = $data[1];

                                    ?><option value="<?php echo($pays); ?>"></option><?php
                                }
                            ?>
                        </datalist>

                        Localité <input list="loc" name="loc" class="form-control" value="<?php echo($locfiltre); ?>">
                        <datalist id="loc">
                            <?php
                                $request = mysqli_query($con, "SELECT DISTINCT localiteProducteur FROM producteur");
                                $nbre = mysqli_num_rows(mysqli_query($con, "SELECT DISTINCT localiteProducteur FROM producteur"));

                                for($i=0; $i < $nbre; $i++)
                                {
                                    $data = mysqli_fetch_array($request);
                                    $loc = $data[0];

                                    ?><option value="<?php echo($loc); ?>"></option><?php
                                }
                            ?>
                        </datalist></br>
                        <input type="submit" value="Filtrer" class="btn btn-vin">
                    </div>
                </div>

<!-- Tri -->
                <div>
                    <h5>Trier par :</h5>
                    <div class="flex-around">
                        <select id="tri" name="tri" class="form-control">
                            <option value="nomtri" <?php if($tri == "nomtri"){ ?> selected <?php } ?>>Nom</option>
                            <option value="loctri" <?php if($tri == "loctri"){ ?> selected <?php } ?>>Localité</option>
                        </select></br>

                        <input type="submit" value="Trier" class="btn btn-vin">
                    </div>
                </div>
            </div>
        </form>

<!-- Requêtes -->
        <?php
            if(isset($_POST["tri"]) != 1)
                $tri = "";
            if(isset($_POST["pays"])) {
                $requesttmp = mysqli_query($con, "SELECT * FROM pays WHERE nomPays LIKE \"$paysfiltre\"");
                $data = mysqli_fetch_array($requesttmp);
                $paysfiltre = $data[0];

                if(htmlspecialchars($_POST["pays"]) != "" && htmlspecialchars($_POST["loc"]) != "") {
                    if($tri == "nomtri") {
                        $request = mysqli_query($con, "SELECT * FROM producteur
                                                        WHERE idPays LIKE \"$paysfiltre\" AND localiteProducteur LIKE \"$locfiltre\" ORDER BY nomProducteur");
                        $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM producteur
                                                                    WHERE idPays LIKE \"$paysfiltre\" AND localiteProducteur LIKE \"$locfiltre\""));
                    } else if($tri == "loctri") {
                        $request = mysqli_query($con, "SELECT * FROM producteur
                                                        WHERE idPays LIKE \"$paysfiltre\" AND localiteProducteur LIKE \"$locfiltre\" ORDER BY localiteProducteur");
                        $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM producteur
                                                                    WHERE idPays LIKE \"$paysfiltre\" AND localiteProducteur LIKE \"$locfiltre\""));
                    } else {
                        $request = mysqli_query($con, "SELECT * FROM producteur
                                                        WHERE idPays LIKE \"$paysfiltre\" AND localiteProducteur LIKE \"$locfiltre\"");
                        $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM producteur
                                                                    WHERE idPays LIKE \"$paysfiltre\" AND localiteProducteur LIKE \"$locfiltre\""));
                    }
                } else if(htmlspecialchars($_POST["pays"]) != "") {
                    if($tri == "nomtri") {
                        $request = mysqli_query($con, "SELECT * FROM producteur
                                                        WHERE idPays LIKE \"$paysfiltre\" ORDER BY nomProducteur");
                        $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM producteur
                                                                    WHERE idPays LIKE \"$paysfiltre\""));
                    } else if($tri == "loctri") {
                        $request = mysqli_query($con, "SELECT * FROM producteur
                                                        WHERE idPays LIKE \"$paysfiltre\" ORDER BY localiteProducteur");
                        $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM producteur
                                                                    WHERE idPays LIKE \"$paysfiltre\""));
                    } else {
                        $request = mysqli_query($con, "SELECT * FROM producteur
                                                        WHERE idPays LIKE \"$paysfiltre\"");
                        $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM producteur
                                                                    WHERE idPays LIKE \"$paysfiltre\""));
                    }
                } else if(htmlspecialchars($_POST["loc"]) != "") {
                    if($tri == "nomtri") {
                        $request = mysqli_query($con, "SELECT * FROM producteur
                                                        WHERE localiteProducteur LIKE \"$locfiltre\" ORDER BY nomProducteur");
                        $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM producteur
                                                                    WHERE localiteProducteur LIKE \"$locfiltre\""));
                    } else if($tri == "loctri") {
                        $request = mysqli_query($con, "SELECT * FROM producteur
                                                        WHERE localiteProducteur LIKE \"$locfiltre\" ORDER BY localiteProducteur");
                        $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM producteur
                                                                    WHERE localiteProducteur LIKE \"$locfiltre\""));
                    } else {
                        $request = mysqli_query($con, "SELECT * FROM producteur
                                                        WHERE localiteProducteur LIKE \"$locfiltre\"");
                        $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM producteur
                                                                    WHERE localiteProducteur LIKE \"$locfiltre\""));
                    }
                } else {
                    if($tri == "nomtri") {
                        $request = mysqli_query($con, "SELECT * FROM producteur ORDER BY nomProducteur");
                        $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM producteur"));
                    } else if($tri == "loctri") {
                        $request = mysqli_query($con, "SELECT * FROM producteur ORDER BY localiteProducteur");
                        $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM producteur"));
                    } else {
                        $request = mysqli_query($con, "SELECT * FROM producteur");
                        $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM producteur"));
                    }
                }
            } else {
                if($tri == "nomtri") {
                    $request = mysqli_query($con, "SELECT * FROM producteur ORDER BY nomProducteur");
                    $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM producteur"));
                } else if($tri == "loctri") {
                    $request = mysqli_query($con, "SELECT * FROM producteur ORDER BY localiteProducteur");
                    $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM producteur"));
                } else {
                    $request = mysqli_query($con, "SELECT * FROM producteur");
                    $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM producteur"));
                }
            }

            ?> <div class="text-center">
                <p>Cliquez sur un producteur pour lui ajouter un vin</p>
            </div> <?php

// Affichage
            for($i = 0; $i < 25 && $i < $nbre; $i++) {
                $data = mysqli_fetch_array($request);
                $id = $data[0];
                $name = $data[1];
                $rue = $data[2];
                $num = $data[3];
                $cpp = $data[4];
                $loc = $data[5];
                $pays = $data[6];
                $requesttmp = mysqli_query($con, "SELECT * FROM pays WHERE idPays LIKE \"$pays\"");
                $data = mysqli_fetch_array($requesttmp);
                $pays = $data[1];
        ?>
                <div class="text-center">
                    <div class="btn btn-vin col-md-6">
                        <div class="flex-around">
                            <div>
                                <?php
                                    echo("Nom : ".ucwords($name)."</br>");
                                    echo("Rue : ".$rue."</br>");
                                    echo("Numéro : ".$num."</br>");
                                ?>
                            </div>
                            <div>
                                <?php
                                    echo("Code postal : ".$cpp."</br>");
                                    echo("Localité : ".ucwords($loc)."</br>");
                                    echo("Pays : ".$pays."</br>");
                                ?>
                            </div>
                        </div>
                    </div>
                    <a class="btn btn-vin col-md-1" href="./vinadd.php?idprod=<?php echo($id); ?>">Ajouter</br>un vin</br></br></a>
                    <a class="btn btn-vin col-md-1" href="./producteuredit.php?idprod=<?php echo($id); ?>"></br>Modifier</br></br></a>
                </div>
        <?php }

// Afficher Plus
            if($nbre > 25 && isset($_GET["all"]) != 1 && isset($_POST["pays"]) != 1) {
        ?>
                <div class="text-center">
                    <a class="btn btn-vin col-md-6" href="./producteur.php?all=1">Afficher tous les producteurs</a>
                </div>    
        <?php }

            for(; (isset($_GET["all"]) || isset($_POST["pays"])) && $i < $nbre; $i++) {
                $data = mysqli_fetch_array($request);
                $id = $data[0];
                $name = $data[1];
                $loc = $data[5];
                $pays = $data[6];
                $requesttmp = mysqli_query($con, "SELECT * FROM pays WHERE idPays LIKE \"$pays\"");
                $data = mysqli_fetch_array($requesttmp);
                $pays = $data[1];

        ?>
                <div class="text-center">
                    <div class="btn btn-vin col-md-6">
                        <div class="flex-around">
                            <div>
                                <?php
                                    echo("Nom : ".ucwords($name)."</br>");
                                    echo("Rue : ".$rue."</br>");
                                    echo("Numéro : ".$num."</br>");
                                ?>
                            </div>
                            <div>
                                <?php
                                    echo("Code postal : ".$cpp."</br>");
                                    echo("Localité : ".ucwords($loc)."</br>");
                                    echo("Pays : ".$pays."</br>");
                                ?>
                            </div>
                        </div>
                    </div>
                    <a class="btn btn-vin col-md-1" href="./vinadd.php?idprod=<?php echo($id); ?>">Ajouter</br>un vin</br></br></a>
                    <a class="btn btn-vin col-md-1" href="./producteuredit.php?idprod=<?php echo($id); ?>"></br>Modifier</br></br></a>
                </div>
        <?php } ?>
    </div>

    <?php require("./include/footer.php"); ?>
</body>
</html>