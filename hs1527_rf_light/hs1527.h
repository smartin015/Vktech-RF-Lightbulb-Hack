/* EV1527, RT1527, FP1527 or HS1527 encoding */

#ifndef HS1527_h
#define HS1527_h
#include "Arduino.h"

class HS1527
{
  public:
    HS1527(int pin); // this is the constructor
    void sendMsg(char *bits, int byte_id);
  private:
    int _pin;	// this is Arduino input pin
    char* _code;
    void signalBinary(boolean state);
    void signalByte(char b);
    void signal(boolean state);
};

#endif
