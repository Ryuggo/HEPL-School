-- Create internal table from external one
DROP TABLE Clients;
DROP TABLE Magasins;
DROP TABLE Articles;
DROP TABLE Ventes;
DROP TABLE Achats;


-- Clients
CREATE TABLE Clients AS
SELECT DISTINCT
    idClient,
    nomClient,
    prenomClient,
    mailClient
FROM VentesExternal;
SELECT * FROM Clients;


-- Magasins
CREATE TABLE Magasins AS
SELECT DISTINCT
    idMagasin,
    nomMagasin,
    codePostal
FROM VentesExternal;
SELECT * FROM Magasins;


-- Articles
DROP TABLE ArticlesTmp;
CREATE TABLE ArticlesTmp (
    numArticle NUMBER(4),
    nomArticle VARCHAR(50),
    prix    FLOAT(8)
);

DECLARE
    TYPE nt_Article   IS TABLE OF VARCHAR (50);
    arti     nt_Article;
BEGIN
    SELECT article BULK COLLECT INTO arti FROM VentesExternal;
    
    FOR i IN 1..arti.COUNT LOOP
        FOR j IN 1..2 LOOP
            INSERT INTO ArticlesTmp
            VALUES (
                CAST(REGEXP_SUBSTR(
                    REGEXP_SUBSTR(arti(i), '(.*)&|(.*)$', 1, j, NULL),
                    '[^.&]*', 1, 1, NULL) AS INTEGER),
                REGEXP_SUBSTR(
                    REGEXP_SUBSTR(arti(i), '(.*)&|(.*)$', 1, j, NULL),
                    '[^.&]*', 1, 3, NULL),
                CAST(REPLACE(REGEXP_SUBSTR(
                    REGEXP_SUBSTR(arti(i), '(.*)&|(.*)$', 1, j, NULL),
                    '[^.&]*', 1, 5, NULL), ',', '.') AS FLOAT)
            );
        END LOOP;
    END LOOP;
END;
/
DROP TABLE Articles;
CREATE TABLE Articles AS
SELECT DISTINCT * FROM ArticlesTmp
WHERE numArticle IS NOT NULL;
DROP TABLE ArticlesTmp;

SELECT * FROM Articles;


-- Ventes
DROP TABLE VentesTmp;
CREATE TABLE VentesTmp (
    idVente     NUMBER(4),
    idClient    NUMBER(4),
    idMagasin   NUMBER(4),
    numArticle  NUMBER(4),
    quantite    NUMBER(4),
    dateAchat   DATE,
    URLTicket   VARCHAR(50)
);

DECLARE
    TYPE nt_Vente     IS TABLE OF INTEGER (4);
    TYPE nt_Client    IS TABLE OF INTEGER (4);
    TYPE nt_Magasin    IS TABLE OF INTEGER (4);
    TYPE nt_Article   IS TABLE OF VARCHAR (50);
    TYPE nt_Date      IS TABLE OF DATE;
    TYPE nt_URL       IS TABLE OF VARCHAR (50);
    
    ven      nt_Vente;
    cli      nt_Client;
    mag      nt_Magasin;
    arti     nt_Article;
    dat      nt_Date;
    url      nt_URL;
BEGIN
    SELECT idVente, idClient, idMagasin, article, dateAchat, URLTicket
    BULK COLLECT INTO ven, cli, mag, arti, dat, url
    FROM VentesExternal;
    
    FOR i IN 1..arti.COUNT LOOP
        FOR j IN 1..2 LOOP
            INSERT INTO VentesTmp
            VALUES (
                ven(i),
                cli(i),
                mag(i),
                CAST(REGEXP_SUBSTR(
                    REGEXP_SUBSTR(arti(i), '(.*)&|(.*)$', 1, j, NULL),
                    '[^.&]*', 1, 1, NULL)AS INTEGER),
                CAST(REGEXP_SUBSTR(
                    REGEXP_SUBSTR(arti(i), '(.*)&|(.*)$', 1, j, NULL),
                    '[^.&]*', 1, 7, NULL)AS INTEGER),
                dat(i),
                url(i)
            );
        END LOOP;
    END LOOP;
END;
/
DROP TABLE Ventes;
CREATE TABLE Ventes AS
SELECT *
FROM VentesTmp
WHERE numArticle IS NOT NULL;
DROP TABLE VentesTmp;

SELECT * FROM Ventes;