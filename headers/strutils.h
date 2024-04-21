#ifndef BREAKOUT_STRUTILS_H
#define BREAKOUT_STRUTILS_H

#include <string.h>

#define MAX_STRING_SIZE 256

void safeStrCopy(char* dest, const char* src, size_t destSize, size_t* actualSize);

#endif