#ifndef BREAKOUT_BLOCKS_H
#define BREAKOUT_BLOCKS_H

#include "entity.h"

int getBlocksNum(int screenWidth);
void placeBlocks(Block* blocks, int numBlocks, int screenWidth);
void removeBlock(Block *block);

#endif