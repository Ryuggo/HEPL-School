<?php
    require("./include/header.php");
    require("./include/connectDB.php");

    $error = array();

// Traitement formulaire
    if(isset($_POST["cuvee"])) {
        $cuvee = htmlspecialchars($_POST["cuvee"]);
        $appel = htmlspecialchars($_POST["appellation"]);
        $region = htmlspecialchars($_POST["region"]);
        $paysvin = htmlspecialchars($_POST["paysvin"]);
        $request = mysqli_query($con, "SELECT * FROM pays WHERE nomPays LIKE \"$paysvin\"");
        $paystmp = mysqli_fetch_array($request);
        $paysv = $paystmp[0];
        $col = htmlspecialchars($_POST["couleur"]);
        $garde = htmlspecialchars($_POST["garde"]);
        if($garde == "")
            $garde = "0000";

            $garde1 = $garde / 100;
            $garde2 = $garde % 100;
        $bio = htmlspecialchars($_POST["bio"]);
        $mill = htmlspecialchars($_POST["millesime"]);

        $prod = htmlspecialchars($_POST["prod"]);
        $rue = htmlspecialchars($_POST["rue"]);
        $numero = htmlspecialchars($_POST["numero"]);
        $cpp = htmlspecialchars($_POST["cpp"]);
        $localite = htmlspecialchars($_POST["localite"]);
        $paysprod = htmlspecialchars($_POST["paysprod"]);
        $request = mysqli_query($con, "SELECT * FROM pays WHERE nomPays LIKE \"$paysprod\"");
        $paystmp = mysqli_fetch_array($request);
        $paysp = $paystmp[0];

// Vérification serveur
        $check = 1;
        $pattern1 = "/^[A-Za-z0-9 \-\._']*$/";
        $pattern2 = "/^[A-Za-z \-']*$/";
        $pattern3 = "/^[A-Za-z0-9]*$/";
        if(!preg_match($pattern1, $cuvee)) {
            $check = 0;
            array_push($error, "Le nom de cuvée a mal été encodé</br>");
        }

        if(!preg_match($pattern1, $appel)) {
            $check = 0;
            array_push($error, "L'appellation a mal été encodée</br>");
        }

        if(!preg_match($pattern2, $region)) {
            $check = 0;
            array_push($error, "La région a mal été encodée</br>");
        }

        if($garde2 < $garde1 || $garde1 < 0 || 99 < $garde1 || $garde2 < 0 || 99 < $garde2) {
            $check = 0;
            array_push($error, "La garde a mal été encodée</br>");
        }

        if($bio < 0 || 1 < $bio) {
            $check = 0;
            array_push($error, "Bio a mal été encodé</br>");
        }

        if($mill < 1800 || date("Y") < $mill) {
            $check = 0;
            array_push($error, "Le millésime a mal été encodé</br>");
        }

        if(!preg_match($pattern1, $prod)) {
            $check = 0;
            array_push($error, "Le nom du producteur a mal été encodé</br>");
        }

        if(!preg_match($pattern1, $rue)) {
            $check = 0;
            array_push($error, "La rue du producteur a mal été encodée</br>");
        }

        if(!preg_match($pattern1, $localite)) {
            $check = 0;
            array_push($error, "La localité du producteur a mal été encodée</br>");
        }

        if(!preg_match($pattern3, $numero)) {
            $check = 0;
            array_push($error, "Le numéro du producteur a mal été encodé</br>");
        }

        if(!preg_match($pattern3, $cpp)) {
            $check = 0;
            array_push($error, "Le code postal du producteur a mal été encodé</br>");
        }

// Mise à Jour DB
        if($check == 1) {
            if($cuvee != " ") {
                if(mysqli_num_rows(mysqli_query($con, "SELECT * FROM producteur
                                                        WHERE nomProducteur LIKE \"$prod\" AND CPProducteur LIKE \"$cpp\" AND localiteProducteur LIKE \"$localite\" AND idPays LIKE \"$paysp\"")) == 0) {
                    $prod = mb_strtolower($prod);
                    $rue = mb_strtolower($rue);
                    $localite = mb_strtolower($localite);
                    $numero = mb_strtoupper($numero);
                    $cpp = mb_strtoupper($cpp);

                    $request = mysqli_query($con, "INSERT INTO producteur VALUES (NULL, \"$prod\", \"$rue\", \"$numero\", \"$cpp\", \"$localite\", \"$paysp\")");

                    if($request == 0)
                        array_push($error, "Problème lors de l'ajout du producteur à la base de données</br>");
                } else {
                    if(mysqli_num_rows(mysqli_query($con, "SELECT * FROM vin
                                                            WHERE nomCuvee LIKE \"$cuvee\" AND appellation LIKE \"$appel\" AND couleur LIKE \"$col\" AND millesime LIKE \"$mill\"")) == 0) {
                        $cuvee = mb_strtolower($cuvee);
                        $region = mb_strtolower($region);
                        $appel = mb_strtolower($appel);

                        $request = mysqli_query($con, "SELECT * FROM producteur
                                                        WHERE nomProducteur LIKE \"$prod\" AND CPProducteur LIKE \"$cpp\" AND localiteProducteur LIKE \"$localite\" AND idPays LIKE \"$paysp\"");
                        $prodtmp = mysqli_fetch_array($request);
                        $idprod = $prodtmp[0];

                        $request = mysqli_query($con, "INSERT INTO vin VALUES (NULL, \"$cuvee\", \"$appel\", \"$region\", \"$paysv\", \"$col\", \"$idprod\", \"$garde\", \"$bio\", \"$mill\")");

                        if($request == 1)
                            header("Location: vin.php");
                        else
                            array_push($error, "Problème lors de l'ajout du vin à la base de données</br>");
                    } else
                        array_push($error, "Le vin de ce producteur a déjà été encodé</br>");

                    $request = 0;
                }

                if($request == 1) {
                    $cuvee = mb_strtolower($cuvee);
                    $region = mb_strtolower($region);
                    $appel = mb_strtolower($appel);

                    $request = mysqli_query($con, "SELECT * FROM producteur
                                                    WHERE nomProducteur LIKE \"$prod\" AND CPProducteur LIKE \"$cpp\" AND localiteProducteur LIKE \"$localite\" AND idPays LIKE \"$paysp\"");
                    $prodtmp = mysqli_fetch_array($request);
                    $idprod = $prodtmp[0];
        
                    $request = mysqli_query($con, "INSERT INTO vin VALUES (NULL, \"$cuvee\", \"$appel\", \"$region\", \"$paysv\", \"$col\", \"$idprod\", \"$garde\", \"$bio\", \"$mill\")");

                    if($request == 1)
                        header("Location: vin.php");
                    else
                        array_push($error, "Problème lors de l'ajout du vin à la base de données</br>");
                }
            }
        }
    } else {
        $cuvee = "";
        $appel = "";
        $region = "";
        $paysvin = "";
        $col = "";
        $garde = "";
        $bio = "";
        $mill = "";

        $prod = "";
        $rue = "";
        $numero = "";
        $cpp = "";
        $localite = "";
        $paysprod = "";
    }

// Auto-remplir les champs du producteur si ajout via producteur
    if(isset($_GET["idprod"])) {
        $idprod = htmlspecialchars($_GET["idprod"]);
        $request = mysqli_query($con, "SELECT * FROM producteur WHERE idProducteur LIKE \"$idprod\"");
        $data = mysqli_fetch_array($request);
        $nametmp = $data[1];
        $ruetmp = $data[2];
        $numtmp = $data[3];
        $cptmp = $data[4];
        $loctmp = $data[5];
        $paystmp = $data[6];
        $request = mysqli_query($con, "SELECT * FROM pays WHERE idPays LIKE \"$paystmp\"");
        $datatmp = mysqli_fetch_array($request);
        $paystmp = $datatmp[1];
    } else {
        $nametmp = $prod;
        $ruetmp = $rue;
        $numtmp = $numero;
        $cptmp = $cpp;
        $loctmp = $localite;
        $paystmp = $paysprod;
    }

    $cuvee = ucwords($cuvee);
    $region = ucwords($region);
    $appel = ucwords($appel);
    $nametmp = ucwords($nametmp);
    $loctmp = ucwords($loctmp);
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <title>Gestion de Vins - Vins Ajout</title>
</head>

<body class="vin">
    <div class="page">
        <form action="" method="post">
            <div class="flex-around">
                <div class="col-md-4">
<!--        Vin         -->
                    <label for="cuvee">Nom cuvée :</label></br>
                        <input type="text" name="cuvee" class="form-control" title="Lettres, chiffres et - _'." value="<?php echo($cuvee); ?>" required id="cuvee" pattern="[A-Za-z0-9\s\-\._']*"></br>

                    <label for="appellation">Appellation :</label></br>
                        <input type="text" name="appellation" class="form-control" title="Lettres, chiffres et - _'." value="<?php echo($appel); ?>" required id="appellation" pattern="[A-Za-z0-9\s\-\._']*"></br>

                    <label for="region">Nom de la région :</label></br>
                        <input type="text" name="region" class="form-control" title="Lettres, chiffres et - '" value="<?php echo($region); ?>" id="region" pattern="[A-Za-z\s\-']*"></br> <!-- Problème quand j'enlève le _ -->

                    <p>Pays</p>
                    <input list="paysvin" name="paysvin" class="form-control" value="<?php echo($paysvin); ?>" required>
                    <datalist id="paysvin">
                        <?php
                            $request = mysqli_query($con, "SELECT * FROM pays");
                            $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM pays"));

                            for($i=0; $i < $nbre; $i++) {
                                $data = mysqli_fetch_array($request);
                                $name = $data[1];

                                ?><option value="<?php echo($name); ?>"></option><?php
                            }
                        ?>
                    </datalist></br>

                    <p>Couleur du vin :</p>
                    <select id="couleur" name="couleur" class="form-control" required>
                        <option value="rgt" <?php if($col == "rgt"){ ?>selected<?php } ?>>Rouge tranquille</option>
                        <option value="blt" <?php if($col == "blt"){ ?>selected<?php } ?>>Blanc tranquille</option>
                        <option value="rst" <?php if($col == "rst"){ ?>selected<?php } ?>>Rose tranquille</option>
                        <option value="ble" <?php if($col == "ble"){ ?>selected<?php } ?>>Blanc effervescent</option>
                        <option value="rse" <?php if($col == "rse"){ ?>selected<?php } ?>>Rose effervescent</option>
                        <option value="rgl" <?php if($col == "rgl"){ ?>selected<?php } ?>>Rouge liquoreux</option>
                        <option value="bll" <?php if($col == "bll"){ ?>selected<?php } ?>>Blanc liquoreux</option>
                    </select></br>

                    <label for="garde">Garde : (de XX à YY année)</label></br>
                        <input type="text" name="garde" class="form-control" title="Les deux premiers chiffres indiquent l'année minimum et les deux derniers le nombre d'année maximum" placeholder="XXYY" value="<?php echo($garde); ?>" pattern="[0-9]{4}" id="garde"></br>

                    <label for="bio"></label></br>
                        <input type="radio" name="bio" value="1" required id="bio" checked> Bio</input></br>
                        <input type="radio" name="bio" value="0" required id="bio"> Non bio</input></br>

                    <label for="millesime">Millésime : (min 1800)</label></br>
                        <input type="number" name="millesime" class="form-control" title="Minimum 1800 et maximum date d'aujourd'hui" value="<?php echo($mill); ?>" required maxlegnth="4" min="1800" max="<?php echo(date("Y")); ?>" id="millesime"></br>
                </div>

                <div class="col-md-4">
<!--    Producteur      -->
                    <label for="prod">Nom du producteur :</label></br>
                        <input type="text" name="prod" class="form-control" title="Lettres, chiffres et - _'." value="<?php echo($nametmp); ?>" required id="prod" pattern="[A-Za-z0-9\s\-\._']*"></br>

                    <label for="rue">Rue du producteur :</label></br>
                        <input type="text" name="rue" class="form-control" title="Lettres, chiffres et - _'." value="<?php echo($ruetmp); ?>" id="rue" pattern="[A-Za-z0-9\s\-\._']*"></br>

                    <label for="numero">Numéro du producteur :</label></br>
                        <input type="text" name="numero" class="form-control" title="Lettres et chiffres" value="<?php echo($numtmp); ?>" maxlength="10" id="numero" pattern="[A-Za-z0-9]*"></br>

                    <label for="cpp">Code postale du producteur :</label></br>
                        <input type="text" name="cpp" class="form-control" title="Lettres et chiffres" value="<?php echo($cptmp); ?>" maxlength="10" required id="cpp" pattern="[A-Za-z0-9]*"></br>

                    <label for="localite">Localité du producteur :</label></br>
                        <input type="text" name="localite" class="form-control" title="Lettres, chiffres et - _'." value="<?php echo($loctmp); ?>" required id="localite" pattern="[A-Za-z0-9\s\-\._']*"></br>

                    <p>Pays du producteur</p>
                    <input list="paysprod" name="paysprod" class="form-control" value="<?php echo($paystmp); ?>" required>
                    <datalist id="paysprod">
                        <?php
                            $request = mysqli_query($con, "SELECT * FROM pays");
                            $nbre = mysqli_num_rows(mysqli_query($con, "SELECT * FROM pays"));

                            for($i=0; $i < $nbre; $i++) {
                                $data = mysqli_fetch_array($request);
                                $name = $data[1];

                                ?><option value="<?php echo($name); ?>"></option><?php
                            }
                        ?>
                    </datalist></br></br>
                </div>
            </div>

            <div class="text-center">
                <?php foreach($error as &$value) { ?>
                    <p class="btn btn-danger"><?php echo($value); ?></p>
                <?php } ?>
            </div>

            <div class="text-center">
                </br>
                <input type="submit" value="Envoyer" class="btn btn-primary">
            </div>
        </form>
    </div>

    <?php require("./include/footer.php"); ?>
</body>
</html>