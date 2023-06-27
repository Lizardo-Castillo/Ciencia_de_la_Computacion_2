<?php
include('config.php');
$idRegistros = $_REQUEST['id'];
$DeleteRegistro = ("DELETE FROM laboratorios WHERE id_laboratorio= '".$idRegistros."' ");
mysqli_query($con, $DeleteRegistro);
?>