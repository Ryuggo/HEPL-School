<footer class="text-center">
    <p>Examen de Juin © <?php echo(date("Y", time()-31536000)." - ".date("Y")); ?> - Mentions légales du projet</p>
</footer>

<?php
    mysqli_close($con);
?>