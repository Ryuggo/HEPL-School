-- Blob
-- GRANT SUR LES ACL (A faire en SYS sur le meme conteneur)
BEGIN
	DBMS_NETWORK_ACL_ADMIN.CREATE_ACL (
		acl => 'aclBlob', 
		description => 'Acces a internet pour les images', 
		principal => 'HUGO',
		is_grant => true,
		privilege => 'connect'
	);

	DBMS_NETWORK_ACL_ADMIN.ASSIGN_ACL(
		acl => 'aclBlob',
		host => 'image.noelshack.com');
END;
/

-- Pour supprimer l'ACL
BEGIN
	DBMS_NETWORK_ACL_ADMIN.DROP_ACL (
		acl => 'aclBlob'
	);
END;
/




-- Dans hugo
DROP TABLE blobtest;
CREATE TABLE blobtest (
	id NUMBER(5) PRIMARY KEY,
	img blob
);

-- SET SERVEROUTPUT ON;
DECLARE
    TYPE nt_Ticket   IS TABLE OF VARCHAR (50);
    ticket     nt_Ticket;

	image blob;
	url VARCHAR(200);
BEGIN
    SELECT URLTicket BULK COLLECT INTO ticket FROM Ventes;

	FOR i IN 1..ticket.COUNT LOOP
		url := concat ('http://image.noelshack.com/', ticket(i));
		image := httpuritype.createuri(url).getblob();
		insert into blobtest values (i, image);
	END LOOP;
	--DBMS_OUTPUT.PUT_LINE(url);
COMMIT;
END;
/
-- To view the blob

-- Open data window of your table.
-- The BLOB cell will be named as (BLOB).
-- Double click the cell.
-- You will see a pencil icon. Click on it.
-- It will open a blob editor window.
-- You would find two check boxes against the option View as : Image or Text.
-- Select the appropriate check box.
-- If above step is still not convincing, then use the Download option.