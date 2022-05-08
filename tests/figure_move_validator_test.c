#include <ctest.h>
#include <libchessviz/figure_move_validator.h>
#include <libchessviz/string_parser.h>

CTEST(figure_move, validate_pawn_motion_two_cells)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, {'1', '|', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'}, {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char input[] = "d2-d4\n";
    Move move = {.color = MoveColorWhite, .type_move = MoveTypeMotion};
    try_parse_input(&move, input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_pawn_w(board, &move));
}

CTEST(figure_move, validate_pawn_motion_one_cell)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, {'1', '|', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'}, {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char input[] = "d2-d3\n";
    Move move = {.color = MoveColorWhite, .type_move = MoveTypeMotion};
    try_parse_input(&move, input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_pawn_w(board, &move));
}

CTEST(figure_move, validate_pawn_motion_three_cell_should_return_error)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, {'1', '|', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'}, {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char input[] = "d2-d5\n";
    Move move = {.color = MoveColorWhite, .type_move = MoveTypeMotion};
    try_parse_input(&move, input);
    ASSERT_EQUAL(ErrorTypeWrongFigureMove, try_move_pawn_w(board, &move));
}

CTEST(figure_move, validate_pawn_motion_back_should_return_error)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'3', '|', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', ' ', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, {'1', '|', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'}, {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char input[] = "a3-a2\n";
    Move move = {.color = MoveColorWhite, .type_move = MoveTypeMotion};
    try_parse_input(&move, input);
    ASSERT_EQUAL(ErrorTypeWrongFigureMove, try_move_pawn_w(board, &move));
}

CTEST(figure_move, validate_pawn_take)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, {'7', '|', 'p', ' ', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', 'p', ' ', ' ', ' ', ' ', ' ', ' '}, {'3', '|', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', ' ', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, {'1', '|', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'}, {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char input[] = "a3xb4\n";
    Move move = {.color = MoveColorWhite, .type_move = MoveTypeTake};
    try_parse_input(&move, input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_pawn_w(board, &move));
}

CTEST(figure_move, validate_rock_motion_x)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', 'R', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, {'1', '|', ' ', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'}, {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char input[] = "a4-g4\n";
    Move move = {.color = MoveColorWhite, .type_move = MoveTypeMotion};
    try_parse_input(&move, input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_rock(board, &move));
}

CTEST(figure_move, validate_rock_motion_y)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'3', '|', 'R', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, {'1', '|', ' ', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'}, {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char input[] = "a3-a6\n";
    Move move = {.color = MoveColorWhite, .type_move = MoveTypeMotion};
    try_parse_input(&move, input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_rock(board, &move));
}

CTEST(figure_move, validate_rock_motion_z_should_return_error)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'3', '|', 'R', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, {'1', '|', ' ', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'}, {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char input[] = "a3-d6\n";
    Move move = {.color = MoveColorWhite, .type_move = MoveTypeMotion};
    try_parse_input(&move, input);
    ASSERT_EQUAL(ErrorTypeWrongFigureMove, try_move_rock(board, &move));
}

CTEST(figure_move, validate_king_motion_x)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', 'K', ' ', ' ', ' ', ' '}, {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, {'1', '|', 'R', 'N', 'B', 'Q', ' ', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'}, {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char first_input[] = "d4-e4\n";
    Move move = {.color = MoveColorWhite, .type_move = MoveTypeMotion};
    try_parse_input(&move, first_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_king(board, &move));

    char second_input[] = "d4-e4\n";
    try_parse_input(&move, second_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_king(board, &move));

    char third_input[] = "e4-g4\n";
    try_parse_input(&move, third_input);
    ASSERT_EQUAL(ErrorTypeWrongFigureMove, try_move_king(board, &move));
}

CTEST(figure_move, validate_king_motion_y)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', 'K', ' ', ' ', ' ', ' '}, {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, {'1', '|', 'R', 'N', 'B', 'Q', ' ', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'}, {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char first_input[] = "d4-d5\n";
    Move move = {.color = MoveColorWhite, .type_move = MoveTypeMotion};
    try_parse_input(&move, first_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_king(board, &move));

    char second_input[] = "d5-d4\n";
    try_parse_input(&move, second_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_king(board, &move));

    char third_input[] = "d4-d6\n";
    try_parse_input(&move, third_input);
    ASSERT_EQUAL(ErrorTypeWrongFigureMove, try_move_king(board, &move));
}

CTEST(figure_move, validate_king_motion_z)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', 'K', ' ', ' ', ' ', ' '}, {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, {'1', '|', 'R', 'N', 'B', 'Q', ' ', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'}, {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};

    char first_input[] = "d4-e5\n";
    Move move = {.color = MoveColorWhite, .type_move = MoveTypeMotion};
    try_parse_input(&move, first_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_king(board, &move));

    char second_input[] = "e5-d4\n";
    try_parse_input(&move, second_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_king(board, &move));

    char third_input[] = "d4-f6\n";
    try_parse_input(&move, third_input);
    ASSERT_EQUAL(ErrorTypeWrongFigureMove, try_move_king(board, &move));
}

CTEST(figure_move, validate_bishop_motion)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'3', '|', ' ', ' ', ' ', 'B', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, {'1', '|', 'R', 'N', ' ', 'Q', 'K', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'}, {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};

    char first_input[] = "d3-g6\n";
    Move move = {.color = MoveColorWhite, .type_move = MoveTypeMotion};
    try_parse_input(&move, first_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_bishop(board, &move));

    char second_input[] = "g6-h5\n";
    try_parse_input(&move, second_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_bishop(board, &move));

    char third_input[] = "h5-h4\n";
    try_parse_input(&move, third_input);
    ASSERT_EQUAL(ErrorTypeWrongFigureMove, try_move_bishop(board, &move));
}

CTEST(figure_move, validate_queen_motion_x)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', 'Q', ' ', ' ', ' ', ' '}, {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, {'1', '|', 'R', 'N', 'B', ' ', 'K', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'}, {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char first_input[] = "d4-e4\n";
    Move move = {.color = MoveColorWhite, .type_move = MoveTypeMotion};
    try_parse_input(&move, first_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_queen(board, &move));

    char second_input[] = "e4-d4\n";
    try_parse_input(&move, second_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_queen(board, &move));

    char third_input[] = "d4-h4\n";
    try_parse_input(&move, third_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_queen(board, &move));
}

CTEST(figure_move, validate_queen_motion_y)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', 'Q', ' ', ' ', ' ', ' '}, {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, {'1', '|', 'R', 'N', 'B', ' ', 'K', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'}, {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char first_input[] = "d4-d6\n";
    Move move = {.color = MoveColorWhite, .type_move = MoveTypeMotion};
    try_parse_input(&move, first_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_queen(board, &move));

    char second_input[] = "d6-d4\n";
    try_parse_input(&move, second_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_queen(board, &move));
}

CTEST(figure_move, validate_queen_motion_z)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', 'Q', ' ', ' ', ' ', ' '}, {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, {'1', '|', 'R', 'N', 'B', ' ', 'K', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'}, {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char first_input[] = "d4-f6\n";
    Move move = {.color = MoveColorWhite, .type_move = MoveTypeMotion};
    try_parse_input(&move, first_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_queen(board, &move));

    char second_input[] = "f6-h4\n";
    try_parse_input(&move, second_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_queen(board, &move));
}

CTEST(figure_move, validate_knight_motion)
{
    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, {'7', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'5', '|', ' ', ' ', ' ', ' ', 'N', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, {'1', '|', 'R', 'N', 'B', 'Q', 'K', 'B', ' ', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'}, {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    char c6_input[] = "e5-c6\n";
    Move move = {.color = MoveColorWhite, .type_move = MoveTypeMotion};
    try_parse_input(&move, c6_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_knight(board, &move));

    char d7_input[] = "e5-d7\n";
    try_parse_input(&move, d7_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_knight(board, &move));

    char f7_input[] = "e5-f7\n";
    try_parse_input(&move, f7_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_knight(board, &move));

    char g6_input[] = "e5-g6\n";
    try_parse_input(&move, g6_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_knight(board, &move));

    char g4_input[] = "e5-g4\n";
    try_parse_input(&move, g4_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_knight(board, &move));

    char f3_input[] = "e5-f3\n";
    try_parse_input(&move, f3_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_knight(board, &move));

    char d3_input[] = "e5-d3\n";
    try_parse_input(&move, d3_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_knight(board, &move));

    char c4_input[] = "e5-c4\n";
    try_parse_input(&move, c4_input);
    ASSERT_EQUAL(ErrorTypeNone, try_move_knight(board, &move));

    char incorrect_input[] = "e5-e6\n";
    try_parse_input(&move, incorrect_input);
    ASSERT_EQUAL(ErrorTypeWrongFigureMove, try_move_knight(board, &move));
}