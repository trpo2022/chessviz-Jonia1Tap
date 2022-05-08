#include <libchessviz/move_maker.h>
#include <ctest.h>

CTEST(move_maker, validate_correct_move_motion_should_return_error_none)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'1', '|', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'},
        {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    Move move = {.type_move = MoveTypeMotion, .x2 = 2, .y2 = 5};
    ASSERT_EQUAL(ErrorTypeNone, try_validate_move(board, &move));
}

CTEST(move_maker, validate_incorrect_move_motion_should_return_error_wrong_move_type)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'1', '|', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'},
        {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    Move move = {.type_move = MoveTypeMotion, .x2 = 2, .y2 = 6};
    ASSERT_EQUAL(ErrorTypeWrongMoveType, try_validate_move(board, &move));
}

CTEST(move_maker, validate_correct_move_take_should_return_error_none)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'7', '|', 'p', ' ', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'5', '|', ' ', 'p', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', ' ', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'1', '|', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'},
        {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    Move move = {.type_move = MoveTypeTake, .x2 = 3, .y2 = 3};
    ASSERT_EQUAL(ErrorTypeNone, try_validate_move(board, &move));
}

CTEST(move_maker, validate_incorrect_move_take_should_return_error_wrong_move_type)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'1', '|', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'},
        {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    Move move = {.type_move = MoveTypeTake, .x2 = 3, .y2 = 3};
    ASSERT_EQUAL(ErrorTypeWrongMoveType, try_validate_move(board, &move));
}

CTEST(move_maker, when_white_pick_white_figure_should_return_error_none)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'1', '|', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'},
        {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    Move move = {.color = MoveColorWhite, .type_move = MoveTypeMotion, .x1 = 2, .y1 = 6, .x2 = 2, .y2 = 5};
    ASSERT_EQUAL(ErrorTypeNone, try_validate_figure(board, &move));
}

CTEST(move_maker, when_white_pick_black_figure_should_return_error_not_own_figure)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'1', '|', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'},
        {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    Move move = {.color = MoveColorWhite, .type_move = MoveTypeMotion, .x1 = 2, .y1 = 2, .x2 = 2, .y2 = 3};
    ASSERT_EQUAL(ErrorTypeDoesNotOwnFigure, try_validate_figure(board, &move));
}

CTEST(move_maker, when_black_pick_black_figure_should_return_error_none)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'1', '|', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'},
        {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    Move move = {.color = MoveColorBlack, .type_move = MoveTypeMotion, .x1 = 2, .y1 = 1, .x2 = 2, .y2 = 3};
    ASSERT_EQUAL(ErrorTypeNone, try_validate_figure(board, &move));
}

CTEST(move_maker, when_black_pick_white_figure_should_return_error_not_own_figure)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'1', '|', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'},
        {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    Move move = {.color = MoveColorBlack, .type_move = MoveTypeMotion, .x1 = 2, .y1 = 6, .x2 = 2, .y2 = 5};
    ASSERT_EQUAL(ErrorTypeDoesNotOwnFigure, try_validate_figure(board, &move));
}

CTEST(move_maker, try_to_kill_own_figure_should_return_error)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'1', '|', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'},
        {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    Move move = {.color = MoveColorBlack, .type_move = MoveTypeTake, .x1 = 2, .y1 = 1, .x2 = 3, .y2 = 0};
    ASSERT_EQUAL(ErrorTypeTryingToKillHisOwnFigure, try_validate_figure(board, &move));
}