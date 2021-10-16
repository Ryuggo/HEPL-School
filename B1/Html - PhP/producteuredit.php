<?php
    require("./include/header.php");
    require("./include/connectDB.php");

    $error = array();

    $idprod = htmlspecialchars($_GET["idprod"]);

// Traitement formulaire
    if(isset($_POST["prod"])) {
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
        $pattern3 = "/^[A-Za-z0-9]*$/";
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
            if($prod != " ") {
                $request = mysqli_query($con, "UPDATE producteur SET nomProducteur = \"$prod\", rueProducteur = \"$rue\", numeroProducteur = \"$numero\", CPProducteur = \"$cpp\", localiteProducteur = \"$localite\", idPays = \"$paysp\"
                                                WHERE idProducteur LIKE \"$idprod\"");

                if($request == 1)
                    header("Location: producteur.php");
                else
                    array_push($error, "Problème lors de la modification du producteur</br>");
            }
        }
    } else {
        $request = mysqli_query($con, "SELECT * FROM producteur WHERE idProducteur LIKE \"$idprod\"");
        $data = mysqli_fetch_array($request);
        $prod = $data[1];
        $rue = $data[2];
        $numero = $data[3];
        $cpp = $data[4];
        $localite = $data[5];
        $paysprod = $data[6];
        $request = mysqli_query($con, "SELECT * FROM pays WHERE idPays LIKE \"$paysprod\"");
        $datatmp = mysqli_fetch_array($request);
        $paysprod = $datatmp[1];
    }

    $prod = ucwords($prod);
    $localite = ucwords($localite);
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <title>Gestion de Vins - Modification Producteur</title>
</head>

<body class="vin">
    <div class="page">
        <form action="" method="post">
            <div class="flex-around">
                <div class="col-md-4">
                    <label for="prod">Nom du producteur :</label></br>
                        <input type="text" name="prod" class="form-control" title="Lettres, chiffres et - _'." value="<?php echo($prod); ?>" required id="prod" pattern="[A-Za-z0-9\s\-\._']*"></br>

                    <label for="rue">Rue du producteur :</label></br>
                        <input type="text" name="rue" class="form-control" title="Lettres, chiffres et - _'." value="<?php echo($rue); ?>" id="rue" pattern="[A-Za-z0-9\s\-\._']*"></br>

                    <label for="numero">Numéro du producteur :</label></br>
                        <input type="text" name="numero" class="form-control" title="Lettres et chiffres" value="<?php echo($numero); ?>" maxlength="10" id="numero" pattern="[A-Za-z0-9]*"></br>

                    <label for="cpp">Code postale du producteur :</label></br>
                        <input type="text" name="cpp" class="form-control" title="Lettres et chiffres" value="<?php echo($cpp); ?>" maxlength="10" required id="cpp" pattern="[A-Za-z0-9]*"></br>

                    <label for="localite">Localité du producteur :</label></br>
                        <input type="text" name="localite" class="form-control" title="Lettres, chiffres et - _'." value="<?php echo($localite); ?>" required id="localite" pattern="[A-Za-z0-9\s\-\._']*"></br>

                    <p>Pays du producteur</p>
                    <input list="paysprod" name="paysprod" class="form-control" value="<?php echo($paysprod); ?>" required>
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