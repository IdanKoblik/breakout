#include "headers/window.h"

void createWindow(Window *window, const char *title, int width, int height) {
    safeStrCopy(window->title, title, sizeof(window->title), &window->titleSize);
    window->height = height;
    window->width = width;
}