cmake_minimum_required(VERSION 3.22)  # ✅ Adicionado para evitar erro

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================

# Importar SDK do Raspberry Pi Pico
include(pico_sdk_import.cmake)  # 🔹 Mantenha esta linha aqui

# Definir o projeto
project(BitMemory C CXX ASM)  # 🔹 O `project()` precisa vir antes do `pico_sdk_init()`

# Inicializar o SDK do Pico
pico_sdk_init()  # ✅ Movido para depois de `project()`

# Definir a placa alvo (Pico padrão)
set(PICO_BOARD pico CACHE STRING "Board type")

# Adicionar executável com os arquivos fonte
add_executable(BitMemory
    src/main.c
    src/MatrizLED.c
    src/Sprite.c
    src/MatrizRenderizador.c
    src/Joystick.c
)

# Definir nome e versão do programa
pico_set_program_name(BitMemory "BitMemory")
pico_set_program_version(BitMemory "0.1")

# Gerar cabeçalho PIO para controle dos LEDs
pico_generate_pio_header(BitMemory ${CMAKE_CURRENT_LIST_DIR}/lib/ws2818b.pio)

# Habilitar saída via UART/USB
pico_enable_stdio_uart(BitMemory 0)
pico_enable_stdio_usb(BitMemory 1)

# Incluir bibliotecas necessárias
target_link_libraries(BitMemory
    pico_stdlib
    hardware_pio
    hardware_clocks
    hardware_adc
    hardware_gpio
)

# Incluir diretórios com cabeçalhos
target_include_directories(BitMemory PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include
)

# Gerar arquivos adicionais (UF2, BIN, HEX, etc.)
pico_add_extra_outputs(BitMemory)
