# Monitoramento Inteligente com IoT — CP2

Projeto desenvolvido para a disciplina de Internet das Coisas (IoT) da FIAP.

---

## Objetivo

Desenvolver um sistema de monitoramento em tempo real capaz de coletar, transmitir, processar, armazenar e visualizar dados ambientais utilizando tecnologias IoT.

---

## Descrição do Projeto

O sistema utiliza um ESP32 com sensores de temperatura (DHT22) e luminosidade (LDR) para coletar dados do ambiente.  
Esses dados são enviados via protocolo MQTT para o broker HiveMQ, consumidos pelo Node-RED para processamento e visualização em dashboard, e armazenados em um banco de dados Oracle.

Além disso, o projeto integra a API OpenWeather para exibir dados climáticos externos.

---

## Arquitetura da Solução

ESP32 (DHT22 + LDR)
        │
        ▼
MQTT (HiveMQ)
        │
        ▼
Node-RED (Dashboard)
        │
 ┌──────┴─────────┐
 ▼                ▼
Oracle DB     OpenWeather API

---

## Tecnologias Utilizadas

- ESP32  
- DHT22 (temperatura)  
- LDR (luminosidade)  
- MQTT (HiveMQ)  
- Node-RED  
- Oracle Database  
- OpenWeather API  
- Wokwi  

---

## Tópicos MQTT

- casa/temperatura  
- casa/luminosidade  

Broker: broker.hivemq.com  
Porta: 1883

---

## Banco de Dados

CREATE TABLE leituras (
  id       NUMBER GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
  sensor   VARCHAR2(50),
  valor    FLOAT,
  momento  TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

---

## Funcionalidades do Dashboard

- Monitoramento em tempo real  
- Indicadores visuais (gauges)  
- Gráficos históricos  
- Alertas automáticos  
- Integração com clima externo  

---

## Integração com API

[https://api.openweathermap.org/data/2.5/weather?q=Sao+Paulo,BR&units=metric&lang=pt_br&appid={API_KEY}](https://api.openweathermap.org/data/2.5/weather?q=Sao+Paulo,BR&appid=35c299e032a62c4494f13c078a2169ea&units=metric&lang=pt_br)


---

## Links do Projeto

Simulação ESP32 (Wokwi):  


Vídeo de demonstração:  
(COLE AQUI O LINK DO VÍDEO)

---

## Instruções de Execução

1. ESP32 (Simulação)
Acesse o link do Wokwi  
Clique em Play  
O envio de dados inicia automaticamente  

2. Node-RED

npm install node-red-dashboard  
npm install node-red-node-mysql  
node-red  

Acesse: [http://localhost:1880 ](http://127.0.0.1:1880/#) 
Importe fluxo_nodered.json  
Configure o banco de dados  
Insira sua API Key  
Clique em Deploy  

3. Dashboard
Acesse: [http://localhost:1880/ui  ](http://127.0.0.1:1880/ui)

4. Banco de Dados
Execute o script script_oracle.sql  

---

## Estrutura do Projeto

cp2-iot-nodered  
 ┣ README.md  
 ┣ sketch.ino  
 ┣ fluxo_nodered.json  
 ┗ script_oracle.sql  

---

## Integrantes

- Marina Tamagnini Magalhães — RM 561786  
- Vitória Valentina Maglio — RM 563509  

---

## Considerações Finais

O projeto demonstra a aplicação prática de IoT, integração de sistemas e análise de dados em tempo real, atendendo aos requisitos da disciplina.
