
<form name="form-data" action="recibLaboratorio.php" method="POST">

    <div class="row">
      
      <div class="col-md-12 mt-2">
          <label for="email" class="form-label">Codigo</label>
          <input type="text" class="form-control" name="codigo" required='true'>
      </div>
      <div class="col-md-12 mt-2">
          <label for="celular" class="form-label">Nombre de lab</label>
          <input type="text" class="form-control" name="laboratorio" required='true'>
      </div>
     

    </div>
      <div class="row justify-content-start text-center mt-5">
          <div class="col-12">
              <button class="btn btn-primary btn-block" id="btnEnviar">
                  Registrar Producto
              </button>
          </div>
      </div>
</form>
