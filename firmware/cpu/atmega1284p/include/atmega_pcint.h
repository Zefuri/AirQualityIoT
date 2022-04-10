#ifndef ATMEGA_PCINT_H
#define ATMEGA_PCINT_H

#ifdef __cplusplus
extern "C" {
#endif

#define ATMEGA_PCINT_MAP_PCINT0 GPIO_PIN(PORT_A, 0), GPIO_PIN(PORT_A, 1), GPIO_PIN(PORT_A, 2), GPIO_PIN(PORT_A, 3), GPIO_PIN(PORT_A, 4), GPIO_PIN(PORT_A, 5), GPIO_PIN(PORT_A, 6), GPIO_PIN(PORT_A, 7)
#define ATMEGA_PCINT_MAP_PCINT1 GPIO_PIN(PORT_B, 0), GPIO_PIN(PORT_B, 1), GPIO_PIN(PORT_B, 2), GPIO_PIN(PORT_B, 3), GPIO_PIN(PORT_B, 4), GPIO_PIN(PORT_B, 5), GPIO_PIN(PORT_B, 6), GPIO_PIN(PORT_B, 7)
#define ATMEGA_PCINT_MAP_PCINT2 GPIO_PIN(PORT_C, 0), GPIO_PIN(PORT_C, 1), GPIO_PIN(PORT_C, 2), GPIO_PIN(PORT_C, 3), GPIO_PIN(PORT_C, 4), GPIO_PIN(PORT_C, 5), GPIO_PIN(PORT_C, 6), GPIO_PIN(PORT_C, 7)
#define ATMEGA_PCINT_MAP_PCINT3 GPIO_PIN(PORT_D, 0), GPIO_PIN(PORT_D, 1), GPIO_PIN(PORT_D, 2), GPIO_PIN(PORT_D, 3), GPIO_PIN(PORT_D, 4), GPIO_PIN(PORT_D, 5), GPIO_PIN(PORT_D, 6), GPIO_PIN(PORT_D, 7)

#ifdef __cplusplus
}
#endif

#endif /* ATMEGA_PCINT_H */
