#include "headers/entity.h"
#include <raylib.h>
#include "headers/blocks.h"

#define BLOCK_WIDTH 25
#define BLOCK_HEIGHT 10
#define BLOCK_SPACING 3
#define NUM_ROWS 3

int getBlocksNum(int screenWidth) {
    int blocksInRow = (screenWidth + BLOCK_SPACING) / (BLOCK_WIDTH + BLOCK_SPACING);
    return blocksInRow * NUM_ROWS;
}

void placeBlocks(Block* blocks, int numBlocks, int screenWidth) {
    Vector2 startPos = {9};
    int index = 0;

    // Initialize blocks and place them
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < numBlocks / NUM_ROWS; col++) {
            blocks[index].width = BLOCK_WIDTH;
            blocks[index].height = BLOCK_HEIGHT;
            blocks[index].position.x = startPos.x + col * (BLOCK_WIDTH + BLOCK_SPACING);
            blocks[index].position.y = startPos.y + row * (BLOCK_HEIGHT + BLOCK_SPACING);
            index++;
        }
    }
}

void removeBlock(Block *block) {
    block->exists = 0;
}
