#ifndef MATRIX_LED_H
#define MATRIX_LED_H

#include <stdint.h>
#include "hardware/pio.h"

// Definições globais
#define MATRIX_LED_COUNT 25
#define MATRIX_LED_PIN 7

// Estrutura para representar um pixel no formato GRB
typedef struct {
    uint8_t green;
    uint8_t red;
    uint8_t blue;
} Pixel;

/**
 * Inicializa a máquina de estado PIO para controlar a matriz de LEDs.
 */
void initializeNeoPixel(uint pin);

/**
 * Retorna o índice de um LED na matriz de 5x5 no formato zig-zag.
 */
int getLEDIndex(int x, int y);

/**
 * Define a intensidade do brilho da matriz de LEDs (0-255).
 */
void setMatrizBrightness(uint8_t intensidade);

/**
 * Define a cor de um LED específico.
 */
void setLEDColor(uint index, uint8_t red, uint8_t green, uint8_t blue);

/*
* Define a cor da matriz com uma matriz 5x5 RGB
*/
void setMatrizLEDColors (uint8_t matriz[5][5][3]);

/**
 * Limpa o buffer de LEDs.
 */
void clearLEDs();

/**
 * Atualiza os LEDs com os dados armazenados no buffer.
 */
void updateLEDs();

#endif // MATRIX_LED_H
