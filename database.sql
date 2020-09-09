DROP TABLE IF EXISTS product;
CREATE TABLE product (
  id BIGINT UNSIGNED NOT NULL AUTO_INCREMENT,
  name TEXT NOT NULL,
  unitPrice BIGINT NOT NULL,
  PRIMARY KEY(id)
);

DROP TABLE IF EXISTS command;
CREATE TABLE command (
  id BIGINT UNSIGNED NOT NULL AUTO_INCREMENT,
  reference TEXT NOT NULL,
  clientName TEXT NOT NULL,
  date DATETIME,
  PRIMARY KEY(id)
);

DROP TABLE IF EXISTS command_products;
CREATE TABLE command_products (
  commandId BIGINT UNSIGNED NOT NULL,
  productId BIGINT UNSIGNED NOT NULL,
  quantity INT,
  PRIMARY KEY(commandId, productId)
);

INSERT INTO product (name, unitPrice) VALUES 
('Steak', 14), ('Paté', 6), ('Glace', 4), ('Patates', 8), ('Menu B2', 21);

INSERT INTO command (reference, clientName, date) VALUES 
('OIA912JAZD', 'Jean Legrand', NOW()), ('OIA912JAZD', 'John Doe', NOW()), ('OIA912JAZD', 'Bastien Leperreux', NOW());

INSERT INTO command_products (commandId, productId, quantity) VALUES 
(1, 2, 3),
(2, 5, 1),
(3, 1, 4),
(1, 3, 9),
(2, 4, 10),
(3, 2, 1),
(2, 2, 2),
(1, 5, 4),
(3, 3, 3),
(1, 4, 10);
