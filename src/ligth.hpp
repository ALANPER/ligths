#ifndef SEMAFORO_HPP
#define SEMAFORO_HPP
#include "mbed.h"

extern DigitalOut ligth[];
extern InterruptIn button;
void clear_all();
void transition();
void yellow_blink();
void start_timer();
void finish_timer();

#endif
