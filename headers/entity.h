#ifndef BREAKOUT_ENTITY_H
#define BREAKOUT_ENTITY_H
#include <raylib.h>

typedef struct {
    float radius;
    Color color;
    struct Vector2 position;
    struct Vector2 velocity; 
} Ball;

typedef struct {
    int width;
    int height;
    Color color;
    struct Vector2 position; 
    int exists;
} Block;

typedef struct {
    int width;
    int height;
    Color color;
    struct Vector2 position; 
    struct Vector2 velocity; 
} Surface;

#endif