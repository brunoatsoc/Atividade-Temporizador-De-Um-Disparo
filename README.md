# Temporizador de Um Disparo

Este projeto implementa um temporizador de um disparo utilizando um Raspberry Pi Pico, simulando o funcionamento no Wokwi através da extensão no VS Code. O sistema aciona um conjunto de LEDs ao pressionar um botão e os desliga gradualmente com um intervalo de 3 segundos entre cada mudança de estado.

## Autor
Projeto criado por Bruno Santos Costa

## Funcionalidades
- O sistema monitora um botão de entrada.
- Ao pressionar o botão, os três LEDs (vermelho, verde e azul) acendem simultaneamente.
- Um temporizador inicia e desliga os LEDs um por um a cada 3 segundos.
- O ciclo se reinicia após o último LED ser desligado.

## Componentes Utilizados
- Raspberry Pi Pico
- LED Vermelho (conectado ao pino 12)
- LED Verde (conectado ao pino 13)
- LED Azul (conectado ao pino 11)
- Botão de pressão (conectado ao pino 5)

## Como Rodar no Wokwi
1. Certifique-se de ter a extensão do Wokwi instalada no VS Code.
2. Clone ou copie este repositório para seu ambiente local.
3. Abra o projeto no VS Code e execute a simulação pela extensão do Wokwi.
