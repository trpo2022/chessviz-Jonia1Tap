#pragma once

#include <libchessviz/move.h>

ErrorType is_correct_pawn_take(Move *move);

ErrorType try_move_pawn_w(char board[COLS][RAWS], Move *move);

ErrorType try_move_pawn_b(char board[COLS][RAWS], Move *move);

ErrorType try_move_rock(char board[COLS][RAWS], Move *move);

ErrorType try_move_knight(char board[COLS][RAWS], Move *move);

ErrorType try_move_bishop(char board[COLS][RAWS], Move *move);

ErrorType try_move_king(char board[COLS][RAWS], Move *move);

ErrorType try_move_queen(char board[COLS][RAWS], Move *move);