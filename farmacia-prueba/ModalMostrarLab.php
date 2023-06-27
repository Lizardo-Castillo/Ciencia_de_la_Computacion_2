<div class="modal fade" id="viewChildresn<?php echo $datalaboratorio['id_laboratorio']; ?>" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="ttext">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header" style="background-color: #563d7c !important;">
        <h6 class="modal-title" style="color: #fff; text-align: center;">
            Mostrar Información
        </h6>
        <button type="button" class="close" data-dismiss="modal" aria-label="Close">
          <span aria-hidden="true">&times;</span>
        </button>
      </div>

      <div class="modal-body">
       
        <p><strong>ID:</strong> <?php echo $datalaboratorio['id_laboratorio']; ?></p>
        <p><strong>Codigo:</strong> <?php echo $datalaboratorio['codigo_laboratorio']; ?></p>
        <p><strong>Nombre de laboratorio:</strong> <?php echo $datalaboratorio['nombre_laboratorio']; ?></p>
        <!-- Y así sucesivamente para todos los datos que quieras mostrar -->
      </div>
            
      <div class="modal-footer">
        <button type="button" class="btn btn-secondary" data-dismiss="modal">Cerrar</button>
      </div>

    </div>
  </div>
</div>
<!---fin ventana Update --->
