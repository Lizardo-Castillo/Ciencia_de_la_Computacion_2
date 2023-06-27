<?php
include('config.php');
$nombre      = $_REQUEST['nombre'];
$correo 	 = $_REQUEST['correo'];
$celular 	 = $_REQUEST['celular'];
$producto 	 = $_REQUEST['producto'];
$lugar  	 = $_REQUEST['lugar'];


$QueryInsert = ("INSERT INTO clientes(
    nombre,
    correo,
    celular,
    producto,
    lugar
)
VALUES (
    '".$nombre. "',
    '".$correo. "',
    '".$celular. "',
    '".$producto. "',
    '".$lugar."'
)");
$inserInmueble = mysqli_query($con, $QueryInsert);

header("location:index.php");
?>
