#ifndef I2C_SLAVE_H
#define I2C_SLAVE_H

#include <avr/interrupt.h>
#include <stdint.h>
#include <util/twi.h>

void I2C_init(uint8_t address);
void I2C_stop(void);
void I2C_setCallbacks(void (*recv)(uint8_t), void (*req)());

typedef enum {NONE_SELECTED = 0, SWITCH_GET_TOP = 1, SWITCH_GET_BOT = 2, LIGHT_SET} opcode_t;

inline void __attribute__((always_inline)) I2C_transmitByte(uint8_t data)
{
  TWDR = data;
}

ISR(TWI_vect);

#endif /* I2C_SLAVE_H */