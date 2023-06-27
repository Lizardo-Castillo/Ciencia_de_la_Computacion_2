
<?php
include('config.php');
$idRegistros = $_REQUEST['id_laboratorio'];
$codigo     = $_REQUEST['codigo_laboratorio'];
$nombre 	 = $_REQUEST['nombre_laboratorio'];


$update = ("UPDATE laboratorios
	SET 
	id_laboratorio  ='" .$idRegistros. "',
	codigo_laboratorio  ='" .$codigo. "',
	nombre_laboratorio ='" .$nombre. "'
	
	

WHERE id_laboratorio='" .$idRegistros. "'
");
$result_update = mysqli_query($con, $update);

echo "<script type='text/javascript'>
        window.location='index.php';
    </script>";

?>
