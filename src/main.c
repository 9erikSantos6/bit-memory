#include <stdio.h>

#include "pico/stdlib.h"
#include "matriz_led.h"
#include "sprite.h"
#include "matriz_renderizador.h"
#include "joystick.h"

int main() {
  // Inicializa as entradas e saídas padrão
  stdio_init_all();

  // Inicializando Joystick
  init_adc();

  // Inicializa a matriz de LEDs NeoPixel
  initializeNeoPixel(MATRIX_LED_PIN);
  setMatrizBrightness(10);
  clearLEDs();

  // Atualiza os LEDs com os dados do buffer
  updateLEDs();

  // Loop infinito para manter o programa rodando
  while (true) {
    desenhar_loading();
    uint adc_x_raw = read_adc_value(1);  // Leitura do eixo X
    uint adc_y_raw = read_adc_value(0);  // Leitura do eixo Y

    uint joy_x_pos = adc_x_raw * BAR_WIDTH / ADC_MAX;
    uint joy_y_pos = adc_y_raw * BAR_WIDTH / ADC_MAX;

    printf("X: %d\nY: %d\n", joy_x_pos, joy_y_pos);
    fflush(stdout);
    sleep_ms(50);
  }

  return 0;
}
