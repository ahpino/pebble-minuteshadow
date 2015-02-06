#include <pebble.h>
#include "numbers.h"

void CreateNumbers(Number* a_Numbers){
    SetNumberRow(a_Numbers[0].numberShape[0], true, true, true);
    SetNumberRow(a_Numbers[0].numberShape[1], true, true, true);
    SetNumberRow(a_Numbers[0].numberShape[2], true, false, true);
    SetNumberRow(a_Numbers[0].numberShape[3], true, false, true);
    SetNumberRow(a_Numbers[0].numberShape[4], true, false, true);
    SetNumberRow(a_Numbers[0].numberShape[5], true, false, true);
    SetNumberRow(a_Numbers[0].numberShape[6], true, false, true);
    SetNumberRow(a_Numbers[0].numberShape[7], true, false, true);
    SetNumberRow(a_Numbers[0].numberShape[8], true, true, true);
    SetNumberRow(a_Numbers[0].numberShape[9], true, true, true);

    SetNumberRow(a_Numbers[1].numberShape[0], false, false, true);
    SetNumberRow(a_Numbers[1].numberShape[1], false, false, true);
    SetNumberRow(a_Numbers[1].numberShape[2], false, false, true);
    SetNumberRow(a_Numbers[1].numberShape[3], false, false, true);
    SetNumberRow(a_Numbers[1].numberShape[4], false, false, true);
    SetNumberRow(a_Numbers[1].numberShape[5], false, false, true);
    SetNumberRow(a_Numbers[1].numberShape[6], false, false, true);
    SetNumberRow(a_Numbers[1].numberShape[7], false, false, true);
    SetNumberRow(a_Numbers[1].numberShape[8], false, false, true);
    SetNumberRow(a_Numbers[1].numberShape[9], false, false, true);

    SetNumberRow(a_Numbers[2].numberShape[0], true, true, true);
    SetNumberRow(a_Numbers[2].numberShape[1], true, true, true);
    SetNumberRow(a_Numbers[2].numberShape[2], false, false, true);
    SetNumberRow(a_Numbers[2].numberShape[3], false, false, true);
    SetNumberRow(a_Numbers[2].numberShape[4], true, true, true);
    SetNumberRow(a_Numbers[2].numberShape[5], true, true, true);
    SetNumberRow(a_Numbers[2].numberShape[6], true, false, false);
    SetNumberRow(a_Numbers[2].numberShape[7], true, false, false);
    SetNumberRow(a_Numbers[2].numberShape[8], true, true, true);
    SetNumberRow(a_Numbers[2].numberShape[9], true, true, true);

    SetNumberRow(a_Numbers[3].numberShape[0], true, true, true);
    SetNumberRow(a_Numbers[3].numberShape[1], true, true, true);
    SetNumberRow(a_Numbers[3].numberShape[2], false, false, true);
    SetNumberRow(a_Numbers[3].numberShape[3], false, false, true);
    SetNumberRow(a_Numbers[3].numberShape[4], true, true, true);
    SetNumberRow(a_Numbers[3].numberShape[5], true, true, true);
    SetNumberRow(a_Numbers[3].numberShape[6], false, false, true);
    SetNumberRow(a_Numbers[3].numberShape[7], false, false, true);
    SetNumberRow(a_Numbers[3].numberShape[8], true, true, true);
    SetNumberRow(a_Numbers[3].numberShape[9], true, true, true);

    SetNumberRow(a_Numbers[4].numberShape[0], true, false, true);
    SetNumberRow(a_Numbers[4].numberShape[1], true, false, true);
    SetNumberRow(a_Numbers[4].numberShape[2], true, false, true);
    SetNumberRow(a_Numbers[4].numberShape[3], true, false, true);
    SetNumberRow(a_Numbers[4].numberShape[4], true, true, true);
    SetNumberRow(a_Numbers[4].numberShape[5], true, true, true);
    SetNumberRow(a_Numbers[4].numberShape[6], false, false, true);
    SetNumberRow(a_Numbers[4].numberShape[7], false, false, true);
    SetNumberRow(a_Numbers[4].numberShape[8], false, false, true);
    SetNumberRow(a_Numbers[4].numberShape[9], false, false, true);

    SetNumberRow(a_Numbers[5].numberShape[0], true, true, true);
    SetNumberRow(a_Numbers[5].numberShape[1], true, true, true);
    SetNumberRow(a_Numbers[5].numberShape[2], true, false, false);
    SetNumberRow(a_Numbers[5].numberShape[3], true, false, false);
    SetNumberRow(a_Numbers[5].numberShape[4], true, true, true);
    SetNumberRow(a_Numbers[5].numberShape[5], true, true, true);
    SetNumberRow(a_Numbers[5].numberShape[6], false, false, true);
    SetNumberRow(a_Numbers[5].numberShape[7], false, false, true);
    SetNumberRow(a_Numbers[5].numberShape[8], true, true, true);
    SetNumberRow(a_Numbers[5].numberShape[9], true, true, true);

    SetNumberRow(a_Numbers[6].numberShape[0], true, true, true);
    SetNumberRow(a_Numbers[6].numberShape[1], true, true, true);
    SetNumberRow(a_Numbers[6].numberShape[2], true, false, false);
    SetNumberRow(a_Numbers[6].numberShape[3], true, false, false);
    SetNumberRow(a_Numbers[6].numberShape[4], true, true, true);
    SetNumberRow(a_Numbers[6].numberShape[5], true, true, true);
    SetNumberRow(a_Numbers[6].numberShape[6], true, false, true);
    SetNumberRow(a_Numbers[6].numberShape[7], true, false, true);
    SetNumberRow(a_Numbers[6].numberShape[8], true, true, true);
    SetNumberRow(a_Numbers[6].numberShape[9], true, true, true);

    SetNumberRow(a_Numbers[7].numberShape[0], true, true, true);
    SetNumberRow(a_Numbers[7].numberShape[1], true, true, true);
    SetNumberRow(a_Numbers[7].numberShape[2], false, false, true);
    SetNumberRow(a_Numbers[7].numberShape[3], false, false, true);
    SetNumberRow(a_Numbers[7].numberShape[4], false, false, true);
    SetNumberRow(a_Numbers[7].numberShape[5], false, false, true);
    SetNumberRow(a_Numbers[7].numberShape[6], false, false, true);
    SetNumberRow(a_Numbers[7].numberShape[7], false, false, true);
    SetNumberRow(a_Numbers[7].numberShape[8], false, false, true);
    SetNumberRow(a_Numbers[7].numberShape[9], false, false, true);

    SetNumberRow(a_Numbers[8].numberShape[0], true, true, true);
    SetNumberRow(a_Numbers[8].numberShape[1], true, true, true);
    SetNumberRow(a_Numbers[8].numberShape[2], true, false, true);
    SetNumberRow(a_Numbers[8].numberShape[3], true, false, true);
    SetNumberRow(a_Numbers[8].numberShape[4], true, true, true);
    SetNumberRow(a_Numbers[8].numberShape[5], true, true, true);
    SetNumberRow(a_Numbers[8].numberShape[6], true, false, true);
    SetNumberRow(a_Numbers[8].numberShape[7], true, false, true);
    SetNumberRow(a_Numbers[8].numberShape[8], true, true, true);
    SetNumberRow(a_Numbers[8].numberShape[9], true, true, true);

    SetNumberRow(a_Numbers[9].numberShape[0], true, true, true);
    SetNumberRow(a_Numbers[9].numberShape[1], true, true, true);
    SetNumberRow(a_Numbers[9].numberShape[2], true, false, true);
    SetNumberRow(a_Numbers[9].numberShape[3], true, false, true);
    SetNumberRow(a_Numbers[9].numberShape[4], true, true, true);
    SetNumberRow(a_Numbers[9].numberShape[5], true, true, true);
    SetNumberRow(a_Numbers[9].numberShape[6], false, false, true);
    SetNumberRow(a_Numbers[9].numberShape[7], false, false, true);
    SetNumberRow(a_Numbers[9].numberShape[8], false, false, true);
    SetNumberRow(a_Numbers[9].numberShape[9], false, false, true);
}

void SetNumberRow(bool* a_Array, bool a_One, bool a_Two, bool a_Three)
{
    memcpy(a_Array, (bool[NUMBER_WIDTH_IN_TILES]){a_One, a_Two, a_Three}, NUMBER_WIDTH_IN_TILES * sizeof(bool));
}
