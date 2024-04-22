#include <raylib.h>
#include "headers/window.h"
#include "headers/blocks.h"
#include "headers/collision.h"
#include <stdlib.h>

#define SURFACE_WIDTH 100
#define SURFACE_HEIGHT 5 
#define ENTITY_SPEED 200
#define DELTA 1
#define TARGET_FPS 60

int main() {
    Window gameWindow;
    const char TITLE[] = "Breakout game";
    createWindow(&gameWindow, TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
    SetTargetFPS(TARGET_FPS);
    InitWindow(gameWindow.width, gameWindow.height, gameWindow.title);

    int numBlocks = getBlocksNum(WINDOW_WIDTH);

    // Allocate memory for the array of blocks
    Block* blocks = (Block*)malloc(numBlocks * sizeof(Block));
    placeBlocks(blocks, numBlocks, WINDOW_WIDTH);

    const float speed = ENTITY_SPEED * DELTA / TARGET_FPS;
    const Color entityColor = WHITE;

    int playerX = WINDOW_WIDTH / 2 + 200;
    Surface player = {SURFACE_WIDTH, SURFACE_HEIGHT, entityColor, {playerX, WINDOW_HEIGHT / 2 + 200}, {speed, speed}};
    Ball ball = {5, entityColor, {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2}, {speed, speed}};    
    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_A)) playerX -= speed;
        if (IsKeyDown(KEY_D)) playerX += speed;

        if (playerX < 0) playerX = 0;
        if (playerX > WINDOW_WIDTH - player.width) playerX = WINDOW_WIDTH - player.width;

        // Move ball
        ball.position.x += ball.velocity.x;
        ball.position.y += ball.velocity.y;

        if (isOutOfBorder(&ball))
            break;

        BeginDrawing();
        ClearBackground(BLACK);
        
        handleBallSurfaceCollision(&ball, &player, playerX);
        handleBorder(&ball);

        // Draw blocks
        for (int i = 0; i < numBlocks; i++) {
            if (blocks[i].exists) {
                DrawRectangle(blocks[i].position.x, blocks[i].position.y, blocks[i].width, blocks[i].height, WHITE);
                if (isBallBlockColliding(&ball, &blocks[i])) {
                    ball.velocity.y *= -1;
                    removeBlock(&blocks[i]);
                }
            }
        }

        DrawRectangle(playerX, player.position.y, player.width, player.height, player.color);
        DrawCircle(ball.position.x, ball.position.y, ball.radius, ball.color);
        EndDrawing();
    }

    free(blocks);

    CloseWindow();

    return 0;
}