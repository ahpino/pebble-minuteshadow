#include <pebble.h>
#include "defines.h"
#include "numbers.h"
#include "configuration.h"

#define NUMBER_OF_TIME_DIGITS 4
#define NUMBER_OF_COLON_DOTS 4

typedef struct {
    GRect area;
    bool fillTile;
} Tile;

typedef struct {
    int tilePosition;
    GPoint point1;
    GPoint point2;
    GColor color;
} Shadow;

// Methods and functions
void Init();
void Deinit();
void MainWindowLoad(Window* a_Window);
void MainWindowUnload(Window* a_Window);
void CreateMatrix();

void OnMinuteEvent(struct tm* a_TickTime, TimeUnits a_UnitsChanged);
void RedrawTime(struct tm* a_TickTime, bool a_RedrawAll);
void SetShadow(struct tm* a_TickTime);
void SetVerticalShadow(struct tm* a_TickTime);
void SetHorizontalShadow(struct tm* a_TickTime);
void SetNumbers(struct tm* a_TickTime);
void SetNumber(int a_Number, GPoint a_InitialPoint);
void SetColon();
void LayerUpdate(Layer* a_Layer, GContext* a_Ctx);

// Global variables
Window* g_MainWindow = NULL;
Layer* g_Layer = NULL;
Shadow g_Shadow = { .tilePosition = 0, .point1 = {.x = 0, .y = 0},
    .point2 = {.x = 0, .y = 0}, .color = GColorBlack};

Tile g_Matrix[MATRIX_NUMBER_VERTICAL_TILES][MATRIX_NUMBER_HORIZONTAL_TILES];
Number g_Numbers[10];
GPoint g_NumbersPosition[NUMBER_OF_TIME_DIGITS] = {{.x = 1, .y = 5},
    {.x = 5, .y = 5}, {.x = 11, .y = 5}, {.x = 15, .y = 5}};
GPoint g_ColonPosition[NUMBER_OF_COLON_DOTS] = {{.x = 9, .y = 7},
    {.x = 9, .y = 8}, {.x = 9, .y = 11}, {.x = 9, .y = 12}};

// Implementation
void Init()
{
    g_MainWindow = window_create();
    window_set_window_handlers(g_MainWindow, (WindowHandlers) {
        .load = MainWindowLoad,
        .unload = MainWindowUnload });

    bool animated = true;
    window_stack_push(g_MainWindow, animated);

    time_t currentTime = time(NULL);
    RedrawTime(localtime(&currentTime), true);
}

void Deinit()
{
    window_destroy(g_MainWindow);
}

void MainWindowLoad(Window* a_Window)
{
    InitConfiguration();

    CreateMatrix();
    CreateNumbers(g_Numbers);

    Layer* windowLayer = window_get_root_layer(g_MainWindow);
    g_Layer = layer_create(GRect(0, 0, WATCH_SCREEN_WIDTH, WATCH_SCREEN_HEIGHT));
    layer_set_update_proc(g_Layer, LayerUpdate);
    layer_add_child(windowLayer, g_Layer);
    
    tick_timer_service_subscribe(SECOND_UNIT, OnMinuteEvent);
}

void MainWindowUnload(Window* a_Window)
{
    tick_timer_service_unsubscribe();
    layer_destroy(g_Layer);
}

void CreateMatrix()
{
    for (int i = 0; i < MATRIX_NUMBER_VERTICAL_TILES; ++i) {
        for (int j = 0; j < MATRIX_NUMBER_HORIZONTAL_TILES; ++j) {
            if (0 == j || (MATRIX_NUMBER_HORIZONTAL_TILES - 1) == j) {
                g_Matrix[i][j].area.origin.x = 0 == j ? 0 : WATCH_SCREEN_WIDTH - MATRIX_TILE_PIXEL_SIZE_W / 2;
                g_Matrix[i][j].area.size.w = MATRIX_TILE_PIXEL_SIZE_W / 2;
            }
            else {
                g_Matrix[i][j].area.origin.x = j * MATRIX_TILE_PIXEL_SIZE_W - MATRIX_TILE_PIXEL_SIZE_W / 2;
                g_Matrix[i][j].area.size.w = MATRIX_TILE_PIXEL_SIZE_W;
            }
            g_Matrix[i][j].area.origin.y = i * MATRIX_TILE_PIXEL_SIZE_H;
            g_Matrix[i][j].area.size.h = MATRIX_TILE_PIXEL_SIZE_H;
            g_Matrix[i][j].fillTile = true;
        }    
    }
}

void OnMinuteEvent(struct tm* a_TickTime, TimeUnits a_UnitsChanged)
{
    RedrawTime(a_TickTime, false);
    layer_mark_dirty(g_Layer);
}

void RedrawTime(struct tm* a_TickTime, bool a_RedrawAll)
{
    SetShadow(a_TickTime);
    SetNumbers(a_TickTime);
    SetColon(a_TickTime);
}

void SetShadow(struct tm* a_TickTime)
{
    if (IsShadowHorizontal()){
        SetHorizontalShadow(a_TickTime);
    }
    else {
        SetVerticalShadow(a_TickTime);
    }
}

void SetVerticalShadow(struct tm* a_TickTime)
{
    bool blackShadow = a_TickTime->tm_min % 2 == 0;

    g_Shadow.color = blackShadow ? GColorBlack : GColorWhite;

    if (a_TickTime->tm_sec < 12) {
        g_Shadow.color = blackShadow ? GColorWhite : GColorBlack;
        g_Shadow.tilePosition = g_NumbersPosition[0].x - 1;
    }
    else if (a_TickTime->tm_sec < 24) {
        g_Shadow.tilePosition = g_NumbersPosition[1].x - 1;
    }
    else if (a_TickTime->tm_sec < 36) {
        g_Shadow.tilePosition = g_ColonPosition[0].x -1;
    }
    else if (a_TickTime->tm_sec < 48) {
        g_Shadow.tilePosition = g_NumbersPosition[2].x - 1;
    }
    else {
        g_Shadow.tilePosition = g_NumbersPosition[3].x - 1;
    }

    g_Shadow.point1.x = g_Shadow.tilePosition <= 0 ?
        0 : g_Shadow.tilePosition * MATRIX_TILE_PIXEL_SIZE_W - MATRIX_TILE_PIXEL_SIZE_W / 2;
    g_Shadow.point1.y = 0;
    g_Shadow.point2.x = g_Shadow.point1.x;
    g_Shadow.point2.y = WATCH_SCREEN_HEIGHT;

    for (int i = 0; i < MATRIX_NUMBER_VERTICAL_TILES; ++i) {
        for (int j = 0; j < MATRIX_NUMBER_HORIZONTAL_TILES; ++j) {
            if (j < g_Shadow.tilePosition) {
                g_Matrix[i][j].fillTile = blackShadow;
            }
            else {
                g_Matrix[i][j].fillTile = !blackShadow;
            }
        }
    }
}

void SetHorizontalShadow(struct tm* a_TickTime)
{
    g_Shadow.tilePosition = a_TickTime->tm_sec * MATRIX_NUMBER_VERTICAL_TILES / SECONDS_IN_A_MINUTE;
    g_Shadow.color = GColorBlack;
    g_Shadow.point1.x = 0;
    g_Shadow.point1.y = g_Shadow.tilePosition * MATRIX_TILE_PIXEL_SIZE_H;
    g_Shadow.point2.x = WATCH_SCREEN_WIDTH;
    g_Shadow.point2.y = g_Shadow.point1.y;

    bool blackShadow = a_TickTime->tm_min % 2 == 0;

    for (int i = 0; i < MATRIX_NUMBER_VERTICAL_TILES; ++i) {
        for (int j = 0; j < MATRIX_NUMBER_HORIZONTAL_TILES; ++j) {
            if (i < g_Shadow.tilePosition) {
                g_Matrix[i][j].fillTile = blackShadow;
            }
            else {
                g_Matrix[i][j].fillTile = !blackShadow;
            }
        }
    }
}

void SetNumbers(struct tm* a_TickTime)
{
    int digit[NUMBER_OF_TIME_DIGITS];
    
    if (clock_is_24h_style()){
        digit[0] = a_TickTime->tm_hour / 10;
        digit[1] = a_TickTime->tm_hour % 10;
    }
    else {
        digit[0] = a_TickTime->tm_hour <= 12 ? a_TickTime->tm_hour / 10 : (a_TickTime->tm_hour - 12) / 10;
        digit[1] = a_TickTime->tm_hour <= 12 ? a_TickTime->tm_hour % 10 : (a_TickTime->tm_hour - 12) % 10;
    }

    digit[2] = a_TickTime->tm_min / 10;
    digit[3] = a_TickTime->tm_min % 10;
    
    for (int i = 0; i < NUMBER_OF_TIME_DIGITS; ++i) {
        SetNumber(digit[i], g_NumbersPosition[i]);        
    }
}

void SetNumber(int a_Number, GPoint a_InitialPoint)
{
    if (a_Number > 9) {
        a_Number = 0;
    }

    int xOffset = a_InitialPoint.x;
    int yOffset = a_InitialPoint.y;

    for (int i = 0; i < NUMBER_HEIGHT_IN_TILES; ++i) {
        for (int j = 0; j < NUMBER_WIDTH_IN_TILES; ++j) {
            if (g_Numbers[a_Number].numberShape[i][j]) {
                g_Matrix[i + yOffset][j + xOffset].fillTile = !g_Matrix[i + yOffset][j + xOffset].fillTile;
            }
        }
    }
}

void SetColon(struct tm* a_TickTime)
{
    for (int i = 0; i < NUMBER_OF_COLON_DOTS; ++i) {
        g_Matrix[g_ColonPosition[i].y][g_ColonPosition[i].x].fillTile =
            !g_Matrix[g_ColonPosition[i].y][g_ColonPosition[i].x].fillTile;
    }
}
void LayerUpdate(Layer* a_Layer, GContext* a_Ctx)
{
    graphics_context_set_stroke_color(a_Ctx, GColorBlack);
    graphics_context_set_fill_color(a_Ctx, GColorBlack);
    
    for (int i = 0; i < MATRIX_NUMBER_VERTICAL_TILES; ++i) {
        for (int j = 0; j < MATRIX_NUMBER_HORIZONTAL_TILES; ++j) {
            if (g_Matrix[i][j].fillTile) {
                graphics_fill_rect(a_Ctx, g_Matrix[i][j].area, 0, GCornersAll);
            }
        }
    }

    graphics_context_set_stroke_color(a_Ctx, g_Shadow.color);
    graphics_context_set_fill_color(a_Ctx, g_Shadow.color);
    graphics_draw_line(a_Ctx, g_Shadow.point1, g_Shadow.point2);
}

int main()
{
    Init();
    app_event_loop();
    Deinit();
}

