-- ============================================
-- Script Oracle - Monitoramento IoT CP2
-- ============================================


CREATE TABLE leituras (
  id        NUMBER GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
  sensor    VARCHAR2(50),
  valor     FLOAT,
  momento   TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

SELECT table_name FROM user_tables WHERE table_name = 'LEITURAS';

INSERT INTO leituras (sensor, valor) VALUES ('temperatura', 24.5);
INSERT INTO leituras (sensor, valor) VALUES ('luminosidade', 1001);
COMMIT;

SELECT * FROM leituras ORDER BY momento DESC;
