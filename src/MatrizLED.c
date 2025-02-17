#include <stdio.h>
#include "matriz_led.h"
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2818b.pio.h"

// Buffer para armazenar o estado de todos os LEDs
static Pixel leds[MATRIX_LED_COUNT];

// Variáveis para controle da máquina de estado PIO
static PIO pio_instance;
static uint state_machine;

// Variável de controle do brilho da matriz (0-255)
static uint8_t matriz_brightness = 10;

/**
 * Inicializa a máquina de estado PIO para controlar a matriz de LEDs.
 */
void initializeNeoPixel(uint pin)
{
  uint program_offset = pio_add_program(pio0, &ws2818b_program);
  pio_instance = pio0;

  state_machine = pio_claim_unused_sm(pio_instance, true); // Tenta no pio0
  if (state_machine == -1) { // Se falhar, tenta no pio1
      pio_instance = pio1;
      state_machine = pio_claim_unused_sm(pio_instance, true);
  }
  if (state_machine == -1) {
      printf("Erro: Nenhuma máquina de estado disponível.\n");
      return;
  }

  ws2818b_program_init(pio_instance, state_machine, program_offset, pin, 800000.f);
  clearLEDs();
}

/**
 * Retorna o índice de um LED na matriz de 5x5 no formato zig-zag.
 */
int getLEDIndex(int x, int y) {
  int newX = y;      // Troca X e Y para corrigir a rotação
  int newY = 4 - x;  // Inverte para alinhar corretamente

  if (newY % 2 == 0) {
    return newY * 5 + newX; // Linha par da esquerda para a direita
  } else {
    return newY * 5 + (4 - newX); // Linha ímpar da direita para a esquerda
  }
}



/*
 * Define a intensidade do brilho da matriz de LEDs (0-255).
 */
void setMatrizBrightness(uint8_t intensidade) {
  if (intensidade > 255) {
    matriz_brightness = 255;
  } else {
    matriz_brightness = intensidade;
  }
}

/**
 * Define a cor de um LED específico, ajustando com o brilho.
 */
void setLEDColor(uint index, uint8_t red, uint8_t green, uint8_t blue)
{
  if (index < MATRIX_LED_COUNT)
  {
    // Multiplicamos os valores por um fator de escala (evita overflow)
    leds[index].red   = (uint8_t)(((uint16_t) red   * matriz_brightness) / 255);
    leds[index].green = (uint8_t)(((uint16_t) green * matriz_brightness) / 255);
    leds[index].blue  = (uint8_t)(((uint16_t) blue  * matriz_brightness) / 255);
  }
}

/**
 * Define um conjunto de cores para a matriz 5x5 RGB.
 */
void setMatrizLEDColors(uint8_t matriz[5][5][3]) {
  for (int linha = 0; linha < 5; linha++) {
    for (int coluna = 0; coluna < 5; coluna++) {
      int posicao = getLEDIndex(linha, coluna);
      setLEDColor(posicao, matriz[linha][coluna][0], matriz[linha][coluna][1], matriz[linha][coluna][2]);
    }
  }
}

/**
 * Limpa o buffer de LEDs, definindo todas as cores como preto.
 */
void clearLEDs()
{
  for (uint i = 0; i < MATRIX_LED_COUNT; ++i)
  {
    setLEDColor(i, 0, 0, 0);
  }
}

/**
 * Envia os dados do buffer para os LEDs.
 */
void updateLEDs()
{
  for (uint i = 0; i < MATRIX_LED_COUNT; ++i)
  {
    pio_sm_put_blocking(pio_instance, state_machine, leds[i].green);
    pio_sm_put_blocking(pio_instance, state_machine, leds[i].red);
    pio_sm_put_blocking(pio_instance, state_machine, leds[i].blue);
  }
  sleep_us(100);
}
