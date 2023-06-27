<?php
include('config.php');
$id      = $_REQUEST['id'];
$codigo 	 = $_REQUEST['codigo'];
$laboratorio 	 = $_REQUEST['laboratorio'];



$QueryLaboratorio = ("INSERT INTO laboratorios(
    id_laboratorio,
    codigo_laboratorio,
    nombre_laboratorio
)
VALUES (
    '".$id. "',
    '".$codigo. "',
    '".$laboratorio. "'
)");
$inserLab = mysqli_query($con, $QueryLaboratorio);

header("location:index.php");
?>
