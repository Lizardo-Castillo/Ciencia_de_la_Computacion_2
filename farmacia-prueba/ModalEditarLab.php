
<!--ventana para Update--->
<div class="modal fade" id="editChildresn<?php echo $datalaboratorio['id_laboratorio']; ?>" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="ttext  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header" style="background-color: #563d7c !important;">
        <h6 class="modal-title" style="color: #fff; text-align: center;">
            Actualizar Información
        </h6>
        <button type="button" class="close" data-dismiss="modal" aria-label="Close">
          <span aria-hidden="true">&times;</span>
        </button>
      </div>


      <form method="POST" action="recibUpdateLab.php">
        <input type="hidden" name="id_laboratorio" value="<?php echo $datalaboratorio['id_laboratorio']; ?>">

            <div class="modal-body" id="cont_modal">

                <div class="form-group">
                  <label for="recipient-name" class="col-form-label">Id:</label>
                  <input type="number" name="id_laboratorio" class="form-control" value="<?php echo $datalaboratorio['id_laboratorio']; ?>" required="true">
                </div>
                <div class="form-group">
                  <label for="recipient-name" class="col-form-label">Codigo:</label>
                  <input type="number" name="codigo_laboratorio" class="form-control" value="<?php echo $datalaboratorio['codigo_laboratorio']; ?>" required="true">
                </div>
                <div class="form-group">
                  <label for="recipient-name" class="col-form-label">Nombre:</label>
                  <input type="text" name="nombre_laboratorio" class="form-control" value="<?php echo $datalaboratorio['nombre_laboratorio']; ?>" required="true">
                </div>
             
                
            </div>
            <div class="modal-footer">
              <button type="button" class="btn btn-secondary" data-dismiss="modal">Cerrar</button>
              <button type="submit" class="btn btn-primary">Guardar Cambios</button>
            </div>
       </form>

    </div>
  </div>
</div>
<!---fin ventana Update --->
