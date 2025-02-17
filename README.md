# BitMemory

BitMemory é um jogo baseado no clássico **Genius**, desenvolvido para a **BitDogLab v6.3** utilizando o **Raspberry Pi Pico W**. O projeto está em desenvolvimento e tem como objetivo explorar interfaces interativas com **LEDs RGB**, **joystick analógico** e **memória sequencial** para criar desafios de memorizacão e reflexos.

## 🚀 Tecnologias Utilizadas

- **Placa:** BitDogLab v6.3 com Raspberry Pi Pico W
- **Linguagem:** C
- **SDK:** Raspberry Pi Pico SDK
- **Hardware:**
  - LEDs NeoPixel (WS2812B)
  - Joystick analógico (ADC)
  - PIO (Programmable I/O)
- **Bibliotecas:**
  - `hardware_adc.h` para leitura do joystick
  - `hardware_pio.h` para controle dos LEDs
  - `pico_stdlib.h` para funcionalidades gerais

## 📂 Estrutura do Projeto

```
BitMemory/
├── CMakeLists.txt          # Configuração do projeto CMake
├── include                 # Arquivos de cabeçalho
│   ├── joystick.h
│   ├── joystick_listener.h
│   ├── matriz_led.h
│   ├── matriz_renderizador.h
│   └── sprite.h
├── lib                     # Biblioteca auxiliar
│   └── ws2818b.pio         # Programa PIO para controle de LEDs
├── pico_sdk_import.cmake   # Importação do SDK do Pico
├── src                     # Código-fonte principal
│   ├── Joystick.c
│   ├── JoystickListener.c
│   ├── main.c              # Arquivo principal do jogo
│   ├── MatrizLED.c
│   ├── MatrizRenderizador.c
│   └── Sprite.c
```

## 🎮 Como Funciona

1. **Iniciação do Hardware:**
   - Inicializa o **joystick analógico** via ADC.
   - Configura os **LEDs RGB NeoPixel** utilizando PIO.
   - Define um brilho padrão para a matriz de LEDs.

2. **Loop Principal:**
   - Exibe a **animação de loading**.
   - Lê os valores do **joystick (X, Y)**.
   - Converte os valores do ADC para coordenadas utilizáveis.
   - Imprime a posição do joystick no console.

## 🛠 Como Compilar e Executar

1. **Clone o repositório:**
   ```sh
   git clone https://github.com/seu-usuario/BitMemory.git
   cd BitMemory
   ```
2. **Configure o ambiente:**
   - Certifique-se de ter o **Raspberry Pi Pico SDK** instalado.
   - Defina o caminho do SDK:
     ```sh
     export PICO_SDK_PATH=/caminho/para/pico-sdk
     ```
3. **Compile o projeto:**
   ```sh
   mkdir build && cd build
   cmake ..
   make
   ```
4. **Carregue no Raspberry Pi Pico W:**
   ```sh
   picotool load BitMemory.uf2
   ```

## 📌 Status do Projeto

🚧 **Em desenvolvimento!** Ainda estamos trabalhando nas funcionalidades principais, melhorias na renderização dos LEDs e interação com o joystick.

## 📢 Contribuição

Se você deseja contribuir com o projeto, sinta-se à vontade para abrir **issues** e **pull requests**!

---

📌 *BitMemory - Um projeto open-source para explorar o Raspberry Pi Pico W e BitDogLab!*

