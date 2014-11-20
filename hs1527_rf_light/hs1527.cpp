/* EV1527, RT1527, FP1527 or HS1527 encoding */

#include "hs1527.h"

#define HS_1527_PULSETIME 474 // Time in microseconds for one pulse


HS1527::HS1527(int pin)
{
  _pin = pin;
}

void HS1527::signal(boolean state) {
  digitalWrite(_pin, state);
  delayMicroseconds(HS_1527_PULSETIME);
}

void HS1527::signalBinary(boolean state) {
  signal(HIGH);
  signal(state);
  signal(state);
  signal(LOW);
}

void HS1527::signalByte(char b) {
  for (int i = 7; i >= 0; i--){
    signalBinary((b >> i) &0x01);
  } 
}

/* Transmit a message */
void HS1527::sendMsg(char * address, int byte_id) {
  /* Sync bit */
  signalBinary(LOW);

  /* Pilot period */
  for(int i = 0; i < 28; ++i) signal(LOW);

  /* 20 Address bits */
  signalByte(address[0]);
  signalByte(address[1]);
  signalByte(address[2] | (1 << byte_id));
}
