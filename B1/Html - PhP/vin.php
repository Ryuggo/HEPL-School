<?php
    require("./include/header.php");
    require("./include/connectDB.php");

// Filtre l'affichage des vins
    if(isset($_POST["appelf"])) {
        $appelf = htmlspecialchars($_POST["appelf"]);
        $couleurf = htmlspecialchars($_POST["couleurf"]);
        $biof = htmlspecialchars($_POST["biof"]);
        $millf = htmlspecialchars($_POST["millf"]);
        $tri = htmlspecialchars($_POST["tri"]);

        if($appelf != "" || $couleurf != "" || $biof != "" || $millf != "")
            $where = " WHERE";
        else
            $where = "";

        if($appelf != "") {
            if($where != " WHERE")
                $where = $where." AND";
            $where = $where." appellation LIKE \"$appelf\"";
        }

        if($couleurf != "") {
            if($where != " WHERE")
                $where = $where." AND";
            $where = $where." couleur LIKE \"$couleurf\"";
        }

        if($biof != "") {
            if($where != " WHERE")
                $where = $where." AND";
            $where = $where." bio LIKE \"$biof\"";
        }

        if($millf != "") {
            if($where != " WHERE")
                $where = $where." AND";
            $where = $where." millesime LIKE \"$millf\"";
        }
        
        if($tri == "millesime")
            $order = " ORDER BY millesime DESC";
        else
            $order = " ORDER BY appellation";
    } else {
        $appelf = "";
        $couleurf = "";
        $biof = "";
        $millf = "";
        $tri = "appeltri";
        $where = "";
        $order = " ORDER BY appellation";
    }
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <title>Gestion de Vins - Vins</title>
</head>

<body class="vin">
    <div class="page">
        <form action="" method="post">
            <div class="flex-around">
<!-- Filtre -->
                <div class="col-md-6">
                    <h5 style="display: flex; justify-content: center;">Filtrer par :</h5>
                    <div  class="flex-around">
                        <p>Appellation
                        <select id="appelf" name="appelf" class="form-control">
                            <option value="" <?php if($appelf == ""){ ?> selected <?php } ?>>-</option>
                            <?php
                                $request = mysqli_query($con, "SELECT DISTINCT appellation FROM vin ORDER BY appellation");
                                $nbre = mysqli_num_rows(mysqli_query($con, "SELECT DISTINCT appellation FROM vin"));

                                for($i=0; $i < $nbre; $i++) {
                                    $data = mysqli_fetch_array($request);
                                    $appel = $data[0];

                                    ?><option value="<?php echo($appel); ?>" <?php if($appelf == $appel){ ?> selected <?php } ?>><?php echo($appel); ?></option><?php
                                }
                            ?>
                        </select></p>

                        <p>Couleur 
                        <select id="couleurf" name="couleurf" class="form-control">
                            <option value="" <?php if($couleurf == ""){ ?> selected <?php } ?>>-</option>
                            <option value="rgt" <?php if($couleurf == "rgt"){ ?>selected<?php } ?>>Rouge tranquille</option>
                            <option value="blt" <?php if($couleurf == "blt"){ ?>selected<?php } ?>>Blanc tranquille</option>
                            <option value="rst" <?php if($couleurf == "rst"){ ?>selected<?php } ?>>Rose tranquille</option>
                            <option value="ble" <?php if($couleurf == "ble"){ ?>selected<?php } ?>>Blanc effervescent</option>
                            <option value="rse" <?php if($couleurf == "rse"){ ?>selected<?php } ?>>Rose effervescent</option>
                            <option value="rgl" <?php if($couleurf == "rgl"){ ?>selected<?php } ?>>Rouge liquoreux</option>
                            <option value="bll" <?php if($couleurf == "bll"){ ?>selected<?php } ?>>Blanc liquoreux</option>
                        </select></p>
                    </div>
                    <div class="flex-around">
                        <p>Bio 
                        <select id="biof" name="biof" class="form-control">
                            <option value="" <?php if($biof == ""){ ?> selected <?php } ?>>-</option>
                            <option value="1" <?php if($biof == "1"){ ?> selected <?php } ?>>Bio</option>
                            <option value="0" <?php if($biof == "0"){ ?> selected <?php } ?>>Non bio</option>
                        </select></p>

                        <p>Millésime
                        <select id="millf" name="millf" class="form-control">
                            <option value="" <?php if($millf == ""){ ?> selected <?php } ?>>-</option>
                            <?php
                                $request = mysqli_query($con, "SELECT DISTINCT millesime FROM vin ORDER BY millesime");
                                $nbre = mysqli_num_rows(mysqli_query($con, "SELECT DISTINCT millesime FROM vin"));

                                for($i=0; $i < $nbre; $i++) {
                                    $data = mysqli_fetch_array($request);
                                    $mill = $data[0];

                                    ?><option value="<?php echo($mill); ?>" <?php if($millf == $mill){ ?> selected <?php } ?>><?php echo($mill); ?></option><?php
                                }
                            ?>
                        </select></p>
                    </div>
                </div>

                <div class="col-md-3" style="display: flex; align-items: center; justify-content: flex-start;">
                    <input type="submit" value="Filtrer" class="btn btn-vin">
                </div>

<!-- Tri -->
                <div class="col-md-3">
                    <h5>Trier par :</h5>
                    <div class="flex-around">
                        <select id="tri" name="tri" class="form-control">
                            <option value="appellation" <?php if($tri == "appellation"){ ?> selected <?php } ?>>Appellation</option>
                            <option value="millesime" <?php if($tri == "millesime"){ ?> selected <?php } ?>>Millésime</option>
                        </select></br>

                        <input type="submit" value="Trier" class="btn btn-vin">
                    </div>
                </div>
            </div>
        </form>

        <div class="text-center">
            <p>Cliquez sur un vin pour l'ajouter comme bouteille</p>
            <a class="btn btn-vin col-md-6" href="./vinadd.php">Ajouter un vin</a>
        </div>

<!-- Requêtes -->
        <?php
            if(isset($_POST["appelf"])) {
                $request = mysqli_query($con, "SELECT * FROM vin".$where.$order);
                $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM vin".$where));
            } else {
                $request = mysqli_query($con, "SELECT * FROM vin".$order);
                $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM vin"));
            }

            for($i = 0; $i < 25 && $i < $nbre; $i++) {
                $data = mysqli_fetch_array($request);
                $id = $data[0];
                $name = $data[1];
                $appel = $data[2];
                $region = $data[3];
                $pays = $data[4];
                $requesttmp = mysqli_query($con, "SELECT * FROM pays WHERE idPays LIKE \"$pays\"");
                $datatmp = mysqli_fetch_array($requesttmp);
                $pays = $datatmp[1];
                $col = $data[5];
                $prod = $data[6];
                $requesttmp = mysqli_query($con, "SELECT * FROM producteur WHERE idProducteur LIKE \"$prod\"");
                $datatmp = mysqli_fetch_array($requesttmp);
                $prod = $datatmp[1];
                $garde = $data[7];
                $bio = $data[8];
                $mill = $data[9];
        ?>
<!-- Affichage -->
                <div class="text-center">
                    <a class="btn btn-vin col-md-6" href="bouteilleadd.php?idvin=<?php echo($id); ?>">
                        <div class="flex-around">
                            <div>
                                <?php
                                    echo("Cuvée : ".ucwords($name)."</br>");
                                    echo("Appellation : ".ucwords($appel)."</br>");
                                    echo("Région : ".ucwords($region)."</br>");
                                    echo("Pays : ".$pays."</br>");
                                ?>
                            </div>
                            <div>
                                <?php
                                    if($garde != "0000") {
                                        $garde1 = round($garde / 100, 0);
                                        $garde2 = $garde % 100;
                                        echo("Garde :</br>De ".$garde1." à ".$garde2." ans</br>");
                                    } else
                                        echo("Garde :</br>De ? à ? ans</br>");
                                    if($bio == 1)
                                        echo("Bio</br>");
                                    else
                                        echo("Non Bio</br>");
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
                                    echo("Producteur :</br>".ucwords($prod)."</br>");
                                ?>
                            </div>
                        </div>
                    </a>
                </div>
        <?php }

// Afficher Plus
            if($nbre > 25 && isset($_GET["all"]) != 1)
            {
        ?>
                <div class="text-center">
                    <a class="btn btn-vin col-md-6" href="./vin.php?all">Afficher tous les vins</a>
                </div>    
        <?php }

            for(; isset($_GET["all"]) && $i < $nbre; $i++) {
                $data = mysqli_fetch_array($request);
                $id = $data[0];
                $name = $data[1];
                $appel = $data[2];
                $region = $data[3];
                $pays = $data[4];
                $requesttmp = mysqli_query($con, "SELECT * FROM pays WHERE idPays LIKE \"$pays\"");
                $datatmp = mysqli_fetch_array($requesttmp);
                $pays = $datatmp[1];
                $col = $data[5];
                $prod = $data[6];
                $requesttmp = mysqli_query($con, "SELECT * FROM producteur WHERE idProducteur LIKE \"$prod\"");
                $datatmp = mysqli_fetch_array($requesttmp);
                $prod = $datatmp[1];
                $garde = $data[7];
                $bio = $data[8];
                $mill = $data[9];
        ?>
                <div class="text-center">
                    <a class="btn btn-vin col-md-6" href="bouteilleadd.php?idvin=<?php echo($id); ?>">
                        <div class="flex-around">
                            <div>
                                <?php
                                    echo("Cuvée : ".ucwords($name)."</br>");
                                    echo("Appellation : ".ucwords($appel)."</br>");
                                    echo("Région : ".ucwords($region)."</br>");
                                    echo("Pays : ".$pays."</br>");
                                ?>
                            </div>
                            <div>
                                <?php
                                    $garde1 = round($garde / 100, 0);
                                    $garde2 = $garde % 100;
                                    echo("Garde :</br>De ".$garde1." à ".$garde2." ans</br>");
                                    if($bio == 1)
                                        echo("Bio</br>");
                                    else
                                        echo("Non Bio</br>");
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
                                    echo("Producteur :</br>".ucwords($prod)."</br>");
                                ?>
                            </div>
                        </div>
                    </a>
                </div>
        <?php } ?>
    </div>
    
    <?php require("./include/footer.php"); ?>
</body>
</html>