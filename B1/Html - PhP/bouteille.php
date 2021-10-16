<?php
    require("./include/header.php");
    require("./include/connectDB.php");

// Filtre
    if(isset($_GET["fcons"])) {
        $fcons = htmlspecialchars($_GET["fcons"]);
    } else {
        $fcons = "noCons";
    }
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <title>Gestion de Vins - Bouteilles</title>
</head>

<body class="bout">
    <div class="page">
        <form action="bouteille.php?fcons=fcons" method="get">
            <div class="flex-around">
<!-- Filtre -->
                <div>
                    <h5>Filtrer par :</h5>
                    <div class="flex-around">
                        <select id="fcons" name="fcons" class="form-control">
                            <option value="Cons" <?php if($fcons == "Cons"){?> selected <?php } ?>>Consommées</option>
                            <option value="noCons" <?php if($fcons == "noCons"){?> selected <?php } ?>>Non consommées</option>
                            <option value="Perime" <?php if($fcons == "Perime"){?> selected <?php } ?>>Garde dépassée</option>
                        </select>
                        
                        <input type="submit" value="Filtrer" class="btn btn-vin">
                    </div>
                </div>
            </div>
        </form>

        <div class="flex-around">
            <div>
                <?php
                    if($fcons == "noCons")
                        echo("Cliquez sur un bouteille pour la consommer</br>");
                    else if($fcons == "Cons")
                        echo("Cliquez sur une bouteille pour voir ses informations de consommation</br>");
                    echo("</br>");
                ?>
            </div>
        </div>

<!-- Requêtes -->
        <?php
            if(isset($_GET["fcons"])) {
                if($fcons == "noCons") {
                    $requestRangee = mysqli_query($con, "SELECT * FROM bouteille INNER JOIN vin ON bouteille.idVin = vin.idVin
                                                        INNER JOIN pays ON vin.idPays = pays.idPays
                                                        WHERE idEmplacement IS NOT NULL AND idConsommation IS NULL
                                                        ORDER BY vin.couleur, pays.nomPays, vin.appellation");
                    $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM bouteille
                                                                WHERE idEmplacement IS NOT NULL AND idConsommation IS NULL"));

                    $requestNonRangee = mysqli_query($con, "SELECT * FROM bouteille INNER JOIN vin ON bouteille.idVin = vin.idVin
                                                            INNER JOIN pays ON vin.idPays = pays.idPays
                                                            WHERE idEmplacement IS NULL AND idConsommation IS NULL
                                                            ORDER BY vin.couleur, pays.nomPays, vin.appellation");
                    $nbre2 = mysqli_num_rows(mysqli_query($con, "SELECT * FROM bouteille
                                                                WHERE idEmplacement IS NULL AND idConsommation IS NULL"));
                } else if($fcons == "Cons") {
                    $requestRangee = mysqli_query($con, "SELECT * FROM bouteille INNER JOIN consommation ON bouteille.idConsommation = consommation.idConsommation
                                                        WHERE bouteille.idConsommation IS NOT NULL
                                                        ORDER BY consommation.DateConsommation");
                    $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM bouteille WHERE idConsommation IS NOT NULL"));
                } else {
                    $requestRangee = mysqli_query($con, "SELECT * FROM bouteille INNER JOIN vin ON bouteille.idVin = vin.idVin
                                                        WHERE (vin.millesime + (vin.garde % 100)) < EXTRACT(YEAR FROM CURRENT_DATE)
                                                        ORDER BY (vin.millesime + (vin.garde % 100))");
                    $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM bouteille INNER JOIN vin ON bouteille.idVin = vin.idVin
                                                                WHERE (vin.millesime + (vin.garde % 100)) < EXTRACT(YEAR FROM CURRENT_DATE)"));
                }
            } else {
                $requestRangee = mysqli_query($con, "SELECT * FROM bouteille INNER JOIN vin ON bouteille.idVin = vin.idVin
                                                    INNER JOIN pays ON vin.idPays = pays.idPays
                                                    WHERE idEmplacement IS NOT NULL AND idConsommation IS NULL
                                                    ORDER BY vin.couleur, pays.nomPays, vin.appellation");
                $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM bouteille
                                                            WHERE idEmplacement IS NOT NULL AND idConsommation IS NULL"));

                $requestNonRangee = mysqli_query($con, "SELECT * FROM bouteille INNER JOIN vin ON bouteille.idVin = vin.idVin
                                                        INNER JOIN pays ON vin.idPays = pays.idPays
                                                        WHERE idEmplacement IS NULL AND idConsommation IS NULL
                                                        ORDER BY vin.couleur, pays.nomPays, vin.appellation");
                $nbre2 = mysqli_num_rows(mysqli_query($con, "SELECT * FROM bouteille
                                                            WHERE idEmplacement IS NULL AND idConsommation IS NULL"));
            }
        ?>
        <div class="flex-around">
<!-- Rangées -->
            <div class="text-center">
        <?php
            if($fcons != "Cons")
                echo("Bouteilles rangées</br>");
            for($i = 0; $i < 25 && $i < $nbre; $i++) {
                $data = mysqli_fetch_array($requestRangee);
                $id = $data[0];
                $date = $data[1];
                $prix = $data[2];
                $cont = $data[3];
                $deg = $data[4];
                $vin = $data[5];

                $request = mysqli_query($con, "SELECT * FROM vin WHERE idVin LIKE \"$vin\"");
                $data = mysqli_fetch_array($request);
                $cuvee = $data[1];
                $appel = $data[2];
                $col = $data[5];
                $garde = $data[7];
                $mill = $data[9];

                $prix /= 100;
                $cont /= 10;
                $deg /= 10;
        ?>
                <div class="text-center">
                    <a class="btn btn-vin" href="<?php if($fcons == "noCons") { ?>
                                                            ./consommation.php?idbout=<?php echo($id); 
                                                        } else if($fcons == "Cons") { ?>
                                                            ./consomee.php?idbout=<?php echo($id); } ?>">
                        <div class="flex-around">
                            <div>
                                <?php
                                    echo("Cuvée : ".ucwords($cuvee)."</br>");
                                    echo("Appellation : ".ucwords($appel)."</br>");
                                    $garde1 = round($garde / 100, 0);
                                    $garde2 = $garde % 100;
                                    echo("Garde :</br>De ".$garde1." à ".$garde2." ans</br>");
                                    echo("Millésime : ".$mill."</br>");
                                ?>
                            </div>
                            <div>
                                <?php
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
                            <div>
                                <?php
                                    echo("Date d'achat : ".$date."</br>");
                                    echo("Prix : ".$prix."</br>");
                                    echo("Contenance : ".$cont."</br>");
                                    echo("Degré : ".$deg."</br>");
                                ?>
                            </div>
                        </div>
                    </a>
                </div>
        <?php }

// Afficher Plus
            if(($nbre > 25 && isset($_GET["all"]) != 1)) {
        ?>
                <div class="text-center">
            <a class="btn btn-vin" href="./bouteille.php?all=1<?php if(isset($_GET["fcons"])){echo("&fcons=".$fcons);} ?>">
                        Afficher toutes les bouteilles
                    </a>
                </div>    
        <?php }

            for(; isset($_GET["all"]) && $i < $nbre; $i++) {
                $data = mysqli_fetch_array($requestRangee);
                $id = $data[0];
                $date = $data[1];
                $prix = $data[2];
                $cont = $data[3];
                $deg = $data[4];
                $vin = $data[5];

                $request = mysqli_query($con, "SELECT * FROM vin WHERE idVin LIKE \"$vin\"");
                $data = mysqli_fetch_array($request);
                $cuvee = $data[1];
                $appel = $data[2];
                $col = $data[5];
                $garde = $data[7];
                $mill = $data[9];

                $prix /= 100;
                $cont /= 10;
                $deg /= 10;
        ?>
                <div class="text-center">
                    <a class="btn btn-vin" href="<?php if($fcons == "noCons") { ?>
                                                            ./consommation.php?idbout=<?php echo($id); 
                                                        } else if($fcons == "Cons") { ?>
                                                            ./consomee.php?idbout=<?php echo($id); } ?>">
                        <div class="flex-around">
                            <div>
                                <?php
                                    echo("Cuvée : ".ucwords($cuvee)."</br>");
                                    echo("Appellation : ".ucwords($appel)."</br>");
                                    $garde1 = round($garde / 100, 0);
                                    $garde2 = $garde % 100;
                                    echo("Garde :</br>De ".$garde1." à ".$garde2." ans</br>");
                                    echo("Millésime : ".$mill."</br>");
                                ?>
                            </div>
                            <div>
                                <?php
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
                            <div>
                                <?php
                                    echo("Date d'achat : ".$date."</br>");
                                    echo("Prix : ".$prix."</br>");
                                    echo("Contenance : ".$cont."</br>");
                                    echo("Degré : ".$deg."</br>");
                                ?>
                            </div>
                        </div>
                    </a>
                </div>
        <?php } ?>
            </div>

<!-- Non rangées -->
        <?php
            if($fcons == "noCons") {
        ?>
            <div class="text-center">
        <?php
            echo("Bouteilles non rangées</br>");
            for($i = 0; $i < 25 && $i < $nbre2; $i++) {
                $data = mysqli_fetch_array($requestNonRangee);
                $id = $data[0];
                $date = $data[1];
                $prix = $data[2];
                $cont = $data[3];
                $deg = $data[4];
                $vin = $data[5];

                $request = mysqli_query($con, "SELECT * FROM vin WHERE idVin LIKE \"$vin\"");
                $data = mysqli_fetch_array($request);
                $cuvee = $data[1];
                $appel = $data[2];
                $col = $data[5];
                $garde = $data[7];
                $mill = $data[9];

                $prix /= 100;
                $cont /= 10;
                $deg /= 10;
        ?>
                <div class="text-center">
                    <a class="btn btn-vin" href="<?php if($fcons == "noCons"){ ?>./consommation.php?idbout=<?php echo($id); ?><?php } ?>">
                        <div class="flex-around">
                            <div>
                                <?php
                                    echo("Cuvée : ".ucwords($cuvee)."</br>");
                                    echo("Appellation : ".ucwords($appel)."</br>");
                                    $garde1 = round($garde / 100, 0);
                                    $garde2 = $garde % 100;
                                    echo("Garde :</br>De ".$garde1." à ".$garde2." ans</br>");
                                    echo("Millésime : ".$mill."</br>");
                                ?>
                            </div>
                            <div>
                                <?php
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
                            <div>
                                <?php
                                    echo("Date d'achat : ".$date."</br>");
                                    echo("Prix : ".$prix."</br>");
                                    echo("Contenance : ".$cont."</br>");
                                    echo("Degré : ".$deg."</br>");
                                ?>
                            </div>
                        </div>
                    </a>
                </div>
        <?php }

// Afficher Plus
            if(($nbre2 > 25 && isset($_GET["all"]) != 1)) {
        ?>
                <div class="text-center">
            <a class="btn btn-vin" href="./bouteille.php?all=1<?php if(isset($_GET["fcons"])){echo("&fcons=".$fcons);} ?>">
                        Afficher toutes les bouteilles
                    </a>
                </div>    
        <?php }

            for(; isset($_GET["all"]) && $i < $nbre2; $i++) {
                $data = mysqli_fetch_array($requestNonRangee);
                $id = $data[0];
                $date = $data[1];
                $prix = $data[2];
                $cont = $data[3];
                $deg = $data[4];
                $vin = $data[5];

                $request = mysqli_query($con, "SELECT * FROM vin WHERE idVin LIKE \"$vin\"");
                $data = mysqli_fetch_array($request);
                $cuvee = $data[1];
                $appel = $data[2];
                $col = $data[5];
                $garde = $data[7];
                $mill = $data[9];

                $prix /= 100;
                $cont /= 10;
                $deg /= 10;
        ?>
                <div class="text-center">
                    <a class="btn btn-vin" href="<?php if($fcons == "noCons"){ ?>./consommation.php?idbout=<?php echo($id); ?><?php } ?>">
                        <div class="flex-around">
                            <div>
                                <?php
                                    echo("Cuvée : ".ucwords($cuvee)."</br>");
                                    echo("Appellation : ".ucwords($appel)."</br>");
                                    $garde1 = round($garde / 100, 0);
                                    $garde2 = $garde % 100;
                                    echo("Garde :</br>De ".$garde1." à ".$garde2." ans</br>");
                                    echo("Millésime : ".$mill."</br>");
                                ?>
                            </div>
                            <div>
                                <?php
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
                            <div>
                                <?php
                                    echo("Date d'achat : ".$date."</br>");
                                    echo("Prix : ".$prix."</br>");
                                    echo("Contenance : ".$cont."</br>");
                                    echo("Degré : ".$deg."</br>");
                                ?>
                            </div>
                        </div>
                    </a>
                </div>
        <?php } ?>
            </div>
        <?php } ?>
        </div>
    </div>

    <?php require("./include/footer.php"); ?>
</body>
</html>