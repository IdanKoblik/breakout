#ifndef BREAKOUT_WINDOW_H
#define BREAKOUT_WINDOW_H

#include "strutils.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 450

typedef struct {
    char title[MAX_STRING_SIZE];
    size_t titleSize;
    int width;
    int height;
} Window;

void createWindow(Window *window, const char *title, int width, int height);

#endif