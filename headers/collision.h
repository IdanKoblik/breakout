#ifndef BREAKOUT_COLLISION_H
#define BREAKOUT_COLLISION_H

#include "entity.h"

int isBallBlockColliding(Ball* ball, Block* block);
void handleBallSurfaceCollision(Ball* ball, Surface* surface, int playerX);
int isOutOfBorder(Ball* ball);
void handleBorder(Ball* ball);

#endif