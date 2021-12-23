DROP TABLE log;
CREATE TABLE log (
    idLog number,
    dateLog DATE,
    resultLog number
);


-- Création d'un DBLink
DROP DATABASE LINK local_link;
CREATE DATABASE LINK local_link CONNECT TO hugo IDENTIFIED BY hugo
USING '(DESCRIPTION=(ADDRESS=(PROTOCOL=TCP)(HOST=localhost)(PORT=1521))(CONNECT_DATA=(SERVER=DEDICATED)(SERVICE_NAME=xe)))';

DROP DATABASE LINK local_link2;
CREATE DATABASE LINK local_link2 CONNECT TO hugo2 IDENTIFIED BY hugo
USING '(DESCRIPTION=(ADDRESS=(PROTOCOL=TCP)(HOST=localhost)(PORT=1521))(CONNECT_DATA=(SERVER=DEDICATED)(SERVICE_NAME=xe)))';


-- 12 rows
insert into log values(
    (SELECT COALESCE(MAX(idLog) + 1, 1) FROM log),
    (SELECT SYSDATE FROM DUAL),
    ((SELECT COUNT(*) FROM ventes@local_link) + (SELECT COUNT(*) FROM ventes@local_link2))
);
select * FROM ventes@local_link;
select * FROM ventes@local_link2;




-- Premier job
BEGIN
  dbms_scheduler.create_job(
      job_name => 'FirstTest',
      job_type => 'PLSQL_BLOCK',
      job_action => 
        'BEGIN insert into log values(
          (SELECT COALESCE(MAX(idLog) + 1, 1) FROM log),
          (SELECT SYSDATE FROM DUAL),
          ((SELECT COUNT(*) FROM ventes@local_link) + (SELECT COUNT(*) FROM ventes@local_link2)));
        commit;  END;',
      start_date => NULL,
      repeat_interval => 'FREQ=DAILY; BYHOUR=9; BYMINUTE=03',
      auto_drop => FALSE,
      comments => 'First test',
      enabled => true
    );
END;
/

-- V�rifier les jobs
select * from user_scheduler_jobs;
select * from log;

-- Forcer le job
BEGIN
	dbms_scheduler.run_job('FirstTest');
END;
/

-- Supprimer le job
BEGIN
	dbms_scheduler.drop_job(
      job_name => 'FirstTest',
      force => true
      );
END;
/

-- ATTENTION
-- Pensez � supprimer les jobs de votre syst�me (si vous n'en voulez plus)