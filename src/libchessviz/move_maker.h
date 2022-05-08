#pragma once

#include <libchessviz/move.h>

ErrorType try_make_move(char board[COLS][RAWS], Move* move, char* inp);
ErrorType try_validate_figure(char board[COLS][RAWS], Move* move);
ErrorType try_validate_move(char board[COLS][RAWS], Move* move);
ErrorType try_move(char board[COLS][RAWS], Move* move);