-- ============================================
-- Script Oracle - Monitoramento IoT CP2
-- ============================================

-- No Oracle NAO se cria DATABASE igual ao MySQL.
-- Voce ja esta dentro do seu schema/usuario.
-- Basta criar a tabela diretamente:

CREATE TABLE leituras (
  id        NUMBER GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
  sensor    VARCHAR2(50),
  valor     FLOAT,
  momento   TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Verificar se a tabela foi criada:
SELECT table_name FROM user_tables WHERE table_name = 'LEITURAS';

-- Inserir dados de teste:
INSERT INTO leituras (sensor, valor) VALUES ('temperatura', 24.5);
INSERT INTO leituras (sensor, valor) VALUES ('luminosidade', 1001);
COMMIT;

-- Consultar os dados:
SELECT * FROM leituras ORDER BY momento DESC;
