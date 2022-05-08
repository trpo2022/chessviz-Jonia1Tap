#pragma once

#define RAWS 11
#define COLS 11

typedef enum
{
    MoveTypeTake = 'x',
    MoveTypeMotion = '-'
} MoveType;

typedef enum
{
    MoveColorWhite,
    MoveColorBlack
} MoveColor;

typedef struct
{
    int x1;
    int y1;
    int x2;
    int y2;
    MoveColor color;
    char* current_color_msg;
    MoveType type_move;
} Move;

typedef enum
{
    ErrorTypeNone,
    ErrorTypeWrongFigureMove = 1,
    ErrorTypeWrongMoveType = 2,
    ErrorTypeIncorrectInput = 3,
    ErrorTypeDoesNotOwnFigure = 4,
    ErrorTypeTryingToKillHisOwnFigure = 5,
} ErrorType;