#include "ili9341.h"
#include "gfx.h"

#ifndef SNAKE_H
#define  SNAKE_H


void snake_init();

void snake_setup();
void snake_run();
void snake_updateDisp();
void snake_endGame();
void snake_putDot(int location, int color);
void generateFood();
#endif