#include <libchessviz/move_maker.h>
#include <libchessviz/string_parser.h>
#include <libchessviz/figure_move_validator.h>

ErrorType try_make_move(char board[COLS][RAWS], Move *move, char *inp)
{
    ErrorType error = try_parse_input(move, inp);
    if (error != 0)
        return error;
    error = try_validate_figure(board, move);
    if (error != 0)
        return error;
    return try_move(board, move);
}

ErrorType try_validate_move(char board[COLS][RAWS], Move *move)
{
    char type = move->type_move;
    char next_tile = board[move->y2][move->x2];
    if (type == MoveTypeTake && next_tile == ' ')
        return ErrorTypeWrongMoveType;
    if (type == MoveTypeMotion && next_tile != ' ')
        return ErrorTypeWrongMoveType;
    return ErrorTypeNone;
}

ErrorType try_validate_figure(char board[COLS][RAWS], Move *move)
{
    char prev_tile = board[move->y1][move->x1];
    char next_tile = board[move->y2][move->x2];
    char *pattern = 0;
    if (move->color == MoveColorWhite)
        pattern = "AZaz";
    else
        pattern = "azAZ";
    if (prev_tile < pattern[0] || prev_tile > pattern[1])
        return ErrorTypeDoesNotOwnFigure;
    int error = try_validate_move(board, move);
    if (error != 0)
        return error;
    if (move->type_move == MoveTypeTake)
        if (next_tile < pattern[2] || next_tile > pattern[3])
            return ErrorTypeTryingToKillHisOwnFigure;
    return ErrorTypeNone;
}

const static ErrorType (*move_validator[])(char board[COLS][RAWS], Move *move) = {
    ['p'] = try_move_pawn_b,
    ['r'] = try_move_rock,
    ['n'] = try_move_knight,
    ['b'] = try_move_bishop,
    ['k'] = try_move_king,
    ['q'] = try_move_queen,
    ['P'] = try_move_pawn_w,
    ['R'] = try_move_rock,
    ['N'] = try_move_knight,
    ['B'] = try_move_bishop,
    ['K'] = try_move_king,
    ['Q'] = try_move_queen,
};

ErrorType try_move(char board[COLS][RAWS], Move *move)
{
    return move_validator[(int)board[move->y1][move->x1]](board, move);
}