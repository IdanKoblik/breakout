#include "headers/entity.h"
#include "headers/collision.h"
#include "headers/window.h"

int isBallBlockColliding(Ball* ball, Block* block) {
    Rectangle blockRect = { block->position.x, block->position.y, block->width, block->height };
    return CheckCollisionCircleRec(ball->position, ball->radius, blockRect); 
}

void handleBallSurfaceCollision(Ball* ball, Surface* surface, int playerX) {
    if (CheckCollisionCircleRec(ball->position, ball->radius, (Rectangle){playerX, surface->position.y, surface->width, surface->height}))
        ball->velocity.y = -ball->velocity.y;
}

void handleBorder(Ball* ball) {
    if (ball->position.x - ball->radius <= 0 || ball->position.x + ball->radius >= WINDOW_WIDTH)
        ball->velocity.x *= -1;
}

int isOutOfBorder(Ball* ball) {
    return ball->position.y > WINDOW_HEIGHT;
}