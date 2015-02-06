#pragma once
#include <pebble.h>

#define HORIZONTAL_SHADOW 0

void InitConfiguration();
void ConfigurationHandler(DictionaryIterator* a_Iterator, void* a_Ctx);
bool IsShadowHorizontal();
