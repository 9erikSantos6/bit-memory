#ifndef SPRITES_H
#define SPRITES_H

#include <stdint.h>

typedef struct {
  uint8_t direita[5][5][3];
  uint8_t esquerda[5][5][3];
  uint8_t baixo[5][5][3];
  uint8_t cima[5][5][3];
  uint8_t coracao[5][5][3];
  uint8_t loading_0[5][5][3];
  uint8_t loading_1[5][5][3];
  uint8_t loading_2[5][5][3];
  uint8_t loading_3[5][5][3];
} SpritesRGB;

extern const SpritesRGB game_spritesRGB;

#endif 