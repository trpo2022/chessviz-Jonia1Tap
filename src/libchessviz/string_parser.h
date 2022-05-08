#pragma once

#include <libchessviz/move.h>

ErrorType try_parse_input(Move* move, char* inp);

char* get_input();

void tolower_string(char* input);

static inline int is_valid_coords(char x, char y)
{
    return (x >= 'a' && x <= 'h') && (y >= '1' && y <= '8');
}

static inline int is_valid_move_type(char type)
{
    return type == 'x' || type == '-';
}