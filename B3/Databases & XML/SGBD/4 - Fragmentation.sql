-- Dans hugo2
-- Création d'un DBLink
DROP DATABASE LINK local_link;
CREATE DATABASE LINK local_link CONNECT TO hugo IDENTIFIED BY hugo
USING '(DESCRIPTION=(ADDRESS=(PROTOCOL=TCP)(HOST=localhost)(PORT=1521))(CONNECT_DATA=(SERVER=DEDICATED)(SERVICE_NAME=xe)))';


-- Création de Magasins
DROP TABLE Magasins;
CREATE TABLE Magasins AS
SELECT * FROM Magasins@local_link
WHERE codePostal >= 5000;

SELECT * FROM Magasins;

-- Retirer les magasins de hugo avec un code postal >= 5000
DELETE FROM Magasins@local_link WHERE codePostal >= 5000;
SELECT * FROM Magasins@local_link;


-- Créations de Ventes
DROP TABLE Ventes;
CREATE TABLE Ventes AS
SELECT idVente, idClient, idMagasin, numArticle, quantite, dateAchat, URLTicket FROM Ventes@local_link INNER JOIN Magasins USING(idMagasin);

SELECT * FROM Ventes;

-- Retirer les ventes de hugo avec les "mauvais" magasins
DELETE FROM Ventes@local_link WHERE idMagasin IN (SELECT idMagasin FROM Magasins);
SELECT * FROM Ventes@local_link;







-- Dans hugo (pas nécessaire -> Tout se fait dans hugo 2)
-- Création  d'un DBLink
DROP DATABASE LINK local_link;
CREATE DATABASE LINK local_link CONNECT TO hugo2 IDENTIFIED BY hugo
USING '(DESCRIPTION=(ADDRESS=(PROTOCOL=TCP)(HOST=localhost)(PORT=1521))(CONNECT_DATA=(SERVER=DEDICATED)(SERVICE_NAME=xe)))';

SELECT * FROM Magasins@local_link;

-- Retirer les magasins avec un code postal >= 5000
DELETE FROM Magasins WHERE codePostal >= 5000;
SELECT * FROM Magasins;
