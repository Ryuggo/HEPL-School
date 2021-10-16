<!-- <?php include("php/connectDB.php"); ?> -->


<div id="Saved_Lists" class="page">
    <section id="Import" class="div-btn"><label for="XlsImport">Importer une liste</label></section>
    <input id="XlsImport" type="file" accept=".xls, .xlsx" onchange="XlsImport(event);" hidden/>


<!-- Not sure if it works, haven't tested it yet 
    <?php
    $result = mysqli_query($mysqli, "SELECT Name FROM jsonFiles");
    if(mysqli_num_rows($result) != 0) {
        ?> <section id="List"> <?php
    }

    for($i = 0; $i < mysqli_num_rows($result); $i++) {
        $data = mysqli_fetch_array($result);
        echo '<div class="div-btn" onclick="Page_Groups();">' . "$data" . '</div>';
    }
    if(mysqli_num_rows($result) != 0) {
        ?> </section> <?php
    } ?>
-->
</div>