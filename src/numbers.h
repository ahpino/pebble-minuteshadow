#pragma once

#include <pebble.h>
#include "defines.h"

typedef struct {
    bool numberShape[NUMBER_HEIGHT_IN_TILES][NUMBER_WIDTH_IN_TILES];
} Number;

void CreateNumbers(Number* a_Numbers);
void SetNumberRow(bool* a_Array, bool a_One, bool a_Two, bool a_Three);
