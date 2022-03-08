<?php
    require("./include/header.php");
    require("./include/connectDB.php");

    $idvin = htmlspecialchars($_GET["idvin"]);

    $error = array();

// Traitement formulaire
    if(isset($_POST["contenance"])) {
        $date = htmlspecialchars($_POST["date"]);
        $prix = htmlspecialchars($_POST["prix"]);
        $cont = htmlspecialchars($_POST["contenance"]);
        $deg = htmlspecialchars($_POST["degre"]);
        $empl = htmlspecialchars($_POST["emplacement"]);
        $quantite = htmlspecialchars($_POST["quantite"]);
        $four = htmlspecialchars($_POST["fournisseur"]);

        if($prix == "")
            $prix = "0.0";
        if($cont == "")
            $cont = "0.0";
        if($deg == "")
            $deg = "0.0";

// Vérification Serveur
        $check = 1;
        $pattern1 = "/^\d+(\.\d{2})$/";
        $pattern2 = "/^\d+(\.\d{1})$/";
        if(!preg_match($pattern1, $prix)) {
            $check = 0;
            array_push($error, "Le prix a mal été encodé</br>");
        }
        if(!preg_match($pattern2, $cont)) {
            $check = 0;
            array_push($error, "La contenance a mal été encodée</br>");
        }
        if(!preg_match($pattern2, $deg)) {
            $check = 0;
            array_push($error, "Le degré d'alcool a mal été encodé</br>");
        }
        if($deg < 0 || 100 < $deg) {
            $check = 0;
            array_push($error, "Le degré d'alcool est trop petit ou trop grand</br>");
        }

// Mise à jour DB
        if($check == 1) {
            if($empl != "vide" && $quantite != 1) {
                array_push($error, "Vous ne pouvez pas mettre plusieurs bouteilles au même emplacement</br>");
            } else {
                if($date == "")
                    $date = "0001-01-01";
                $prix *= 100;
                $cont *= 10;
                $deg *= 10;

                if($empl == "vide" && $four == "vide")
                    for($i = 0; $i < $quantite; $i++)
                        $request = mysqli_query($con, "INSERT INTO bouteille VALUES (NULL, \"$date\", \"$prix\", \"$cont\", \"$deg\", \"$idvin\", NULL, NULL, NULL)");
                else if($empl == "vide")
                    for($i = 0; $i < $quantite; $i++)
                        $request = mysqli_query($con, "INSERT INTO bouteille VALUES (NULL, \"$date\", \"$prix\", \"$cont\", \"$deg\", \"$idvin\", NULL, NULL, \"$four\")");
                else if($four == "vide")
                    for($i = 0; $i < $quantite; $i++)
                        $request = mysqli_query($con, "INSERT INTO bouteille VALUES (NULL, \"$date\", \"$prix\", \"$cont\", \"$deg\", \"$idvin\", \"$empl\", NULL, NULL)");
                else
                    for($i = 0; $i < $quantite; $i++)
                        $request = mysqli_query($con, "INSERT INTO bouteille VALUES (NULL, \"$date\", \"$prix\", \"$cont\", \"$deg\", \"$idvin\", \"$empl\", NULL, \"$four\")");
                
                if($request == 1)
                    header("Location: bouteille.php");
                else
                    array_push($error, "Problème lors de l'ajout de la bouteille à la base de données</br>");
            }
        } else {
            if($prix == "0.0")
                $prix = "";
            if($cont == "0.0")
                $cont = "";
            if($deg == "0.0")
                $deg = "";
        }
    } else {
        $date = "";
        $prix = "";
        $cont = "";
        $deg = "";
        $empl = "";
        $quantite = 1;
        $four = "";
    }

// Infos supplémentraires sur le vin
    $request = mysqli_query($con, "SELECT * FROM vin WHERE idVin LIKE \"$idvin\"");
    $data = mysqli_fetch_array($request);
    $name = $data[1];
    $appel = $data[2];
    $region = $data[3];
    $pays = $data[4];
    $requesttmp = mysqli_query($con, "SELECT * FROM pays WHERE idPays LIKE \"$pays\"");
    $datatmp = mysqli_fetch_array($requesttmp);
    $pays = $datatmp[1];
    $col = $data[5];
    $idprod = $data[6];
    $requesttmp = mysqli_query($con, "SELECT * FROM producteur WHERE idProducteur LIKE \"$idprod\"");
    $datatmp = mysqli_fetch_array($requesttmp);
    $prod = $datatmp[1];
    $garde = $data[7];
    $bio = $data[8];
    $mill = $data[9];
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <title>Gestion de Vins - Bouteilles Ajout</title>
</head>

<body class="bout">
    <div class="page">
        <form action="" method="post">
            <div class="flex-around">
                <div class="col-md-4" class="text-center">
                    <label for="date">Date d'achat :</label></br>
                    <input type="date" name="date" class="form-control" value="<?php echo($date); ?>" min="<?php echo($mill."-01-01"); ?>" max="<?php echo(date("Y-m-d")); ?>" id="date"></br>

                    <label for="prix">Prix d'achat : (€)</label></br>
                    <input type="text" name="prix" class="form-control" title="Format : xx.xx" placeholder="12.25" value="<?php echo($prix); ?>" id="prix" pattern="^\d+(\.\d{2})$" title="test"></br>

                    <label for="contenance">Contenance : (cl)</label></br>
                    <input type="text" name="contenance" class="form-control" title="Format : xx.x" placeholder="75.5" value="<?php echo($cont); ?>" required id="contenance" pattern="^\d+(\.\d{1})$"></br>

                    <label for="degre">Degré d'alcool : (%)</label></br>
                    <input type="text" name="degre" class="form-control" title="Format : xx.x" placeholder="23.6" value="<?php echo($deg); ?>" id="degre" pattern="^\d+(\.\d{1})$"></br>

                    <p>Emplacement de rangement :</p>
                    <select id="emplacement" name="emplacement" class="form-control">
                        <option value="vide" <?php if($empl == ""){ ?>selected<?php } ?>>Ne pas ranger</option>
                        <?php
                            $requestEmpl = mysqli_query($con, "SELECT * FROM emplacement
                                                                LEFT JOIN bouteille ON emplacement.idEmplacement = bouteille.idEmplacement
                                                                WHERE bouteille.idEmplacement IS NULL");
                            $nbrEmpl = mysqli_num_rows(mysqli_query($con, "SELECT * FROM emplacement
                                                                            LEFT JOIN bouteille ON emplacement.idEmplacement = bouteille.idEmplacement
                                                                            WHERE bouteille.idEmplacement IS NULL"));

                            $request = mysqli_query($con, "SELECT * FROM bouteille");
                            $nbreBout = mysqli_num_rows(mysqli_query($con, "SELECT * FROM bouteille"));

                            for($i = 0; $i < $nbrEmpl; $i++) {
                                $data = mysqli_fetch_array($requestEmpl);
                                $idEmpl = $data[0];
                                $nomEmpl = $data[1];
                                $rangEmpl = $data[2];
                                $colEmpl = $data[3];
                                ?><option value="<?php echo($idEmpl); ?>" <?php if($empl == "$idEmpl"){ ?>selected<?php } ?>><?php echo($nomEmpl." - ".$rangEmpl."".$colEmpl); ?></option><?php
                            }
                        ?>
                    </select>
                
                    <label for="quantite">Nombre de bouteilles à ajouter :</label></br>
                    <input type="number" name="quantite" class="form-control" title="Vous ne pouvez pas prendre plus que 1 si vous choisissez un emplacement" value="<?php echo($quantite); ?>" min="1" id="quantite"></br>

                    <p>Fournisseur du vin :</p>
                    <select id="fournisseur" name="fournisseur" class="form-control">
                        <option value="vide" <?php if($four == ""){ ?>selected<?php } ?>>Inconnu</option>
                        <?php
                            $request = mysqli_query($con, "SELECT * FROM fournisseur");
                            $nbreFour = mysqli_num_rows(mysqli_query($con, "SELECT * FROM fournisseur"));

                            for($i = 0; $i < $nbreFour; $i++) {
                                $data = mysqli_fetch_array($request);
                                $idFour = $data[0];
                                $nomFour = $data[1];
                                ?><option value="<?php echo($idFour); ?>" <?php if($four == "$idFour"){ ?>selected<?php } ?>><?php echo($nomFour); ?></option><?php
                            }
                        ?>
                    </select></br>

                    <div class="text-center">
                        <?php foreach($error as &$value) { ?>
                            <p class="btn btn-danger"><?php echo($value); ?></p>
                        <?php } ?>
                    </div>

                    </br>
                    <input type="submit" value="Envoyer" class="btn btn-primary">
                </div>

<!-- Infos supplémentaires sur le vin -->
                <div class="col-md-4" class="text-center">
                    <?php
                        echo("Cuvée : ".ucwords($name)."</br>");
                        echo("Appellation : ".ucwords($appel)."</br>");
                        echo("Région : ".ucwords($region)."</br>");
                        echo("Pays : ".$pays."</br>");
                            if($col == "rgt")
                                $col = "Rouge Tranquille";
                            else if($col == "blt")
                                $col = "Blanc Tranquille";
                            else if($col == "rst")
                                $col = "Rose Tranquille";
                            else if($col == "ble")
                                $col = "Blanc Effervescent";
                            else if($col == "rse")
                                $col = "Rose Effervescent";
                            else if($col == "rgl")
                                $col = "Rouge Liquoreux";
                            else if($col == "rsl")
                                $col = "Rose Liquoreux";
                        echo("Couleur : ".$col."</br>");
                        $garde1 = round($garde / 100, 0);
                        $garde2 = $garde % 100;
                        echo("Garde : De ".$garde1." à ".$garde2." ans</br>");
                        if($bio == 1)
                            echo("Bio</br>");
                        else
                            echo("Non Bio</br>");
                        echo("Millésime : ".$mill."</br>");
                        echo("</br>");
                        echo("Producteur : ".ucwords($prod)."</br>");
                    ?>
                </div>
            </div>
        </form>
    </div>

    <?php require("./include/footer.php"); ?>
</body>
</html>