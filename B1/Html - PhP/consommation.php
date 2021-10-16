<?php
    require("./include/header.php");
    require("./include/connectDB.php");

    $idbout = htmlspecialchars($_GET["idbout"]);

// Traitement formulaire
    if(isset($_POST["date"])) {
        $date = htmlspecialchars($_POST["date"]);
        $note = htmlspecialchars($_POST["note"]);
        $note = mb_strtolower($note);

// Mise à jour DB
        $request = mysqli_query($con, "INSERT INTO consommation VALUES (NULL, \"$date\", \"$note\")");
        $request = mysqli_query($con, "SELECT * FROM consommation WHERE DateConsommation LIKE \"$date\" AND notesConsommation LIKE \"$note\"");
        $data = mysqli_fetch_array($request);
        $idcons = $data[0];

        $request = mysqli_query($con, "UPDATE bouteille SET idEmplacement = NULL, idConsommation = \"$idcons\" WHERE idBouteille LIKE \"$idbout\"");
        
        if($request == 1)
            header("Location: bouteille.php");
        else
            array_push($error, "Problème lors de l'ajout de la bouteille à la base de données</br>");
    } else {
        $date = "";
        $note = "";
    }

    $note = ucfirst($note);

    $request = mysqli_query($con, "SELECT * FROM bouteille WHERE idBouteille LIKE \"$idbout\"");
    $data = mysqli_fetch_array($request);
    $dateachat = $data[1];
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <title>Gestion de Vins - Consommation</title>
</head>

<body class="bout">
    <div class="page">
        <form action="" method="post">
            <div class="flex-around">
                <div class="col-md-4">
<!--        Vin         -->
                    <label for="date">Date de consommation :</label></br>
                        <input type="date" name="date" class="form-control" value="<?php echo($date); ?>" min="<?php echo($dateachat); ?>" max="<?php echo(date("Y-m-d")); ?>" required id="date"></br>

                    <label for="note">Note :</label></br>
                        <input type="text" name="note" class="form-control" value="<?php echo($note); ?>" id="note"></br>
                </div>
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