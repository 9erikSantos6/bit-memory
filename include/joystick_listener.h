#ifndef JOYSTICK_LISTENER_H
#define JOYSTICK_LISTENER_H

#include <stdint.h>

typedef struct {
  uint8_t cima;
  uint8_t baixo;
  uint8_t esquerda;
  uint8_t direita;
} JoystickDirection;

extern const JoystickDirection joystick_direction;

#endif
