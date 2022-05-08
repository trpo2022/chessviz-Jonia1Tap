#include <libchessviz/figure_move_validator.h>

ErrorType try_check_y(char board[COLS][RAWS], Move* move)
{
    int i, c1 = move->y1, c2 = move->y2;
    if (move->x1 != move->x2)
        return ErrorTypeWrongFigureMove;

    if (move->y1 > move->y2)
    {
        c1 = move->y2;
        c2 = move->y1;
    }

    for (i = c1 + 1; i < c2; i++)
        if (board[i][move->x1] != ' ')
            return ErrorTypeWrongFigureMove;

    return ErrorTypeNone;
}

ErrorType try_check_x(char board[COLS][RAWS], Move* move)
{
    int i, c1 = move->x1, c2 = move->x2;

    if (move->y1 != move->y2)
        return ErrorTypeWrongFigureMove;

    if (move->x1 > move->x2)
    {
        c1 = move->x2;
        c2 = move->x1;
    }

    for (i = c1 + 1; i < c2; i++)
        if (board[move->y1][i] != ' ')
            return ErrorTypeWrongFigureMove;

    return ErrorTypeNone;
}

ErrorType try_check_d(char board[COLS][RAWS], Move* move)
{
    int i, j, c1 = move->y2, c2 = move->y1, ci, cj;

    if (((move->y2 - move->y1) != (move->x2 - move->x1)) && ((move->y2 - move->y1) != (move->x1 - move->x2)))
        return ErrorTypeWrongFigureMove;

    if (move->y2 > move->y1)
    {
        c1 = move->y1;
        c2 = move->y2;
        ci = 1;
    }
    else
    {
        ci = -1;
    }

    if (move->x2 > move->x1)
        cj = 1;
    else
        cj = -1;

    i = move->y1 + ci;
    j = move->x1 + cj;

    while ((i < c2) && (i > c1))
    {
        if (board[i][j] != ' ')
            return ErrorTypeWrongFigureMove;
        i += ci;
        j += cj;
    }

    return ErrorTypeNone;
}

ErrorType is_correct_pawn_take(Move* move)
{
    int delta_x = move->x2 - move->x1;
    int delta_y = move->y2 - move->y1;
    if (((delta_x == 1) || (delta_x == -1)) && (delta_y == -1))
        return ErrorTypeNone;
    return ErrorTypeWrongFigureMove;
}

ErrorType try_move_pawn_w(char board[COLS][RAWS], Move* move)
{
    int delta_y = move->y1 - move->y2;
    if (move->type_move == MoveTypeTake)
        return is_correct_pawn_take(move);
    if (delta_y != 1 && (move->y1 != 6))
        return ErrorTypeWrongFigureMove;
    if ((delta_y > 2 || delta_y < 1) && (move->y1 == 6))
        return ErrorTypeWrongFigureMove;
    return try_check_y(board, move);
}

ErrorType try_move_pawn_b(char board[COLS][RAWS], Move* move)
{
    int delta_y = move->y2 - move->y1;
    if (move->type_move == MoveTypeTake)
        return is_correct_pawn_take(move);
    if (delta_y != 1 && (move->y1 != 1))
        return ErrorTypeWrongFigureMove;
    if ((delta_y > 2 || delta_y < 1) && (move->y1 == 1))
        return ErrorTypeWrongFigureMove;
    return try_check_y(board, move);
}

ErrorType try_move_rock(char board[COLS][RAWS], Move* move)
{
    if (move->y1 == move->y2)
        return try_check_x(board, move);
    else if (move->x1 == move->x2)
        return try_check_y(board, move);
    return ErrorTypeWrongFigureMove;
}

ErrorType try_move_knight(char board[COLS][RAWS], Move* move)
{
    if ((move->y1 - move->y2 == 2) && (move->x1 - move->x2 == 1))
        return ErrorTypeNone;
    if ((move->y2 - move->y1 == 2) && (move->x2 - move->x1 == 1))
        return ErrorTypeNone;
    if ((move->y2 - move->y1 == 2) && (move->x1 - move->x2 == 1))
        return ErrorTypeNone;
    if ((move->y1 - move->y2 == 2) && (move->x2 - move->x1 == 1))
        return ErrorTypeNone;
    if ((move->y1 - move->y2 == 1) && (move->x2 - move->x1 == 2))
        return ErrorTypeNone;
    if ((move->y2 - move->y1 == 1) && (move->x2 - move->x1 == 2))
        return ErrorTypeNone;
    if ((move->y1 - move->y2 == 1) && (move->x1 - move->x2 == 2))
        return ErrorTypeNone;
    if ((move->y2 - move->y1 == 1) && (move->x1 - move->x2 == 2))
        return ErrorTypeNone;
    return ErrorTypeWrongFigureMove;
}

ErrorType try_move_bishop(char board[COLS][RAWS], Move* move)
{
    return try_check_d(board, move);
}

ErrorType try_move_king(char board[COLS][RAWS], Move* move)
{
    int f_delta_y = move->y1 - move->y2;
    int s_delta_y = move->y2 - move->y1;
    int f_delta_x = move->x1 - move->x2;
    int s_delta_x = move->x2 - move->x1;
    if ((f_delta_y != 1) && (s_delta_y != 1) && ((f_delta_x != 1) && (s_delta_x != 1)))
        return ErrorTypeWrongFigureMove;
    return ErrorTypeNone;
}

ErrorType try_move_queen(char board[COLS][RAWS], Move* move)
{
    if (move->y1 == move->y2)
        return try_check_x(board, move);
    else if (move->x1 == move->x2)
        return try_check_y(board, move);
    return try_check_d(board, move);
}