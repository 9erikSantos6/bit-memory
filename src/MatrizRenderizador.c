#include "matriz_renderizador.h"
#include "pico/stdlib.h"
#include "sprite.h"

/**
 * Animação de loading usando sprites RGB.
 */
void desenhar_loading() {
  uint8_t (*loading_frames[])[5][5][3] = {
      &game_spritesRGB.loading_0,
      &game_spritesRGB.loading_1,
      &game_spritesRGB.loading_2,
      &game_spritesRGB.loading_3
  };
  clearLEDs();
  for (int i = 0; i < 4; i++) {
    setMatrizLEDColors(*loading_frames[i]); // Desreferencia o ponteiro corretamente
    updateLEDs();
    sleep_ms(200);
  }
}

void desenhar_seta_direita() {
  setMatrizLEDColors(&game_spritesRGB.direita);
  updateLEDs();
}

void desenhar_seta_esquerda() {
  setMatrizLEDColors(&game_spritesRGB.esquerda);
  updateLEDs();
}

void desenhar_seta_cima() {
  setMatrizLEDColors(&game_spritesRGB.cima);
  updateLEDs();
}

void desenhar_seta_baixo() {
  setMatrizLEDColors(&game_spritesRGB.baixo);
  updateLEDs();
}