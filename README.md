# Projeto: Semáforo com LED RGB - BitDogLab

## Descrição
Este projeto implementa um semáforo utilizando um LED RGB conectado à placa **BitDogLab**. O controle da iluminação segue a sequência padrão de semáforo: vermelho, amarelo e verde, alternando a cada 3 segundos por meio de um temporizador. Além disso, uma mensagem é impressa no terminal a cada 1 segundo para indicar que o sistema está em funcionamento.

## Requisitos
- Placa **BitDogLab**
- LED RGB integrado (GPIOs 11, 12 e 13)
- Biblioteca **Pico SDK**

## Configuração dos GPIOs
| Cor do LED | GPIO |
|------------|------|
| Vermelho   | 13   |
| Verde      | 11   |
| Amarelo    | 12   |

## Funcionalidades
- O LED inicia na cor **vermelha**.
- Após 3 segundos, troca para **amarelo**.
- Após mais 3 segundos, troca para **verde**.
- O ciclo se repete indefinidamente.
- O loop principal exibe "Funcionando" a cada 1 segundo na porta serial.

## Instalação e Execução
1. Configure o ambiente de desenvolvimento para a **Raspberry Pi Pico** e **BitDogLab**.
2. Compile e carregue o firmware na placa.
3. Conecte-se via monitor serial para visualizar as mensagens.

## Estrutura do Código
- **init()**: Inicializa os GPIOs.
- **callback()**: Função chamada pelo temporizador para alternar os LEDs.
- **alternar_leds()**: Alterna a iluminação do LED RGB.
- **main()**: Configura o temporizador e imprime mensagens no terminal.

## Exemplo de Saída Serial
```
Funcionando
Funcionando
Funcionando
```

