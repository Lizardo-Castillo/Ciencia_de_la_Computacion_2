CREATE DATABASE IF NOT EXISTS farmacia;
USE farmacia;

-- Tabla laboratorios
CREATE TABLE IF NOT EXISTS laboratorios (
  id_laboratorio INT AUTO_INCREMENT PRIMARY KEY,
  codigo_laboratorio VARCHAR(3) NOT NULL,
  nombre_laboratorio VARCHAR(50) NOT NULL
);

-- Tabla lineas
CREATE TABLE IF NOT EXISTS lineas (
  id_linea INT AUTO_INCREMENT PRIMARY KEY,
  codigo_linea VARCHAR(5) NOT NULL,
  nombre_linea VARCHAR(50) NOT NULL,
  id_laboratorio INT NOT NULL,
  FOREIGN KEY (id_laboratorio) REFERENCES laboratorios (id_laboratorio)
);

-- Tabla productos
CREATE TABLE IF NOT EXISTS productos (
  id_producto INT AUTO_INCREMENT PRIMARY KEY,
  codigo_producto VARCHAR(6) NOT NULL,
  nombre_producto VARCHAR(50) NOT NULL,
  cantidad INT NOT NULL,
  precio_unitario DECIMAL(10,2) NOT NULL,
  precio_total DECIMAL(10,2) NOT NULL,
  vencimiento DATE NOT NULL,
  id_linea INT NOT NULL,
  FOREIGN KEY (id_linea) REFERENCES lineas (id_linea)
);

-- Trigger para generar codigo_laboratorio autoincremental
DELIMITER $$
CREATE TRIGGER tr_incremental_laboratorio BEFORE INSERT ON laboratorios
FOR EACH ROW
BEGIN
  DECLARE ultimo_codigo VARCHAR(3);
  SELECT codigo_laboratorio FROM laboratorios ORDER BY id_laboratorio DESC LIMIT 1 INTO ultimo_codigo;
  IF ultimo_codigo IS NULL THEN
    SET NEW.codigo_laboratorio = '01';
  ELSE
    SET NEW.codigo_laboratorio = LPAD(CAST(SUBSTR(ultimo_codigo, 1, 2) AS UNSIGNED) + 1, 2, '0');
  END IF;
END$$
DELIMITER ;

-- Trigger para generar codigo_linea autoincremental
DELIMITER $$
CREATE TRIGGER tr_incremental_linea BEFORE INSERT ON lineas
FOR EACH ROW
BEGIN
  DECLARE ultimo_codigo VARCHAR(5);
  SELECT codigo_linea FROM lineas ORDER BY id_linea DESC LIMIT 1 INTO ultimo_codigo;
  IF ultimo_codigo IS NULL THEN
    SET NEW.codigo_linea = CONCAT((SELECT codigo_laboratorio FROM laboratorios WHERE id_laboratorio = NEW.id_laboratorio), '01');
  ELSE
    SET NEW.codigo_linea = CONCAT((SELECT codigo_laboratorio FROM laboratorios WHERE id_laboratorio = NEW.id_laboratorio), LPAD(CAST(SUBSTR(ultimo_codigo, 3, 2) AS UNSIGNED) + 1, 2, '0'));
  END IF;
END$$
DELIMITER ;

-- Trigger para generar codigo_producto autoincremental
DELIMITER $$
CREATE TRIGGER tr_incremental_producto BEFORE INSERT ON productos
FOR EACH ROW
BEGIN
  DECLARE ultimo_codigo VARCHAR(6);
  SELECT codigo_producto FROM productos ORDER BY id_producto DESC LIMIT 1 INTO ultimo_codigo;
  IF ultimo_codigo IS NULL THEN
    SET NEW.codigo_producto = CONCAT((SELECT codigo_linea FROM lineas WHERE id_linea = NEW.id_linea), '01');
  ELSE
    SET NEW.codigo_producto = CONCAT((SELECT codigo_linea FROM lineas WHERE id_linea = NEW.id_linea), LPAD(CAST(SUBSTR(ultimo_codigo, 6, 1) AS UNSIGNED) + 1, 1, '0'));
  END IF;
  -- Actualiza el total_labor
