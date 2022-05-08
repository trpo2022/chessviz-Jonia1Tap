#include <libchessviz/cli_interface.h>
#include <libchessviz/move.h>
#include <libchessviz/move_maker.h>
#include <libchessviz/string_parser.h>
#include <stdio.h>
#include <stdlib.h>

void change_board(char board[COLS][RAWS], Move* move)
{
    board[move->y2][move->x2] = board[move->y1][move->x1];
    board[move->y1][move->x1] = ' ';
}

const char* ErrorMsg[] = {
    [ErrorTypeNone] = "",
    [ErrorTypeWrongFigureMove] = "It is forbidden to move the figures in this way.\n",
    [ErrorTypeWrongMoveType] = "Invalid move type.\n",
    [ErrorTypeIncorrectInput] = "Invalid input, please try again.\n",
    [ErrorTypeDoesNotOwnFigure] = "You are trying to play not with your figure.\n",
    [ErrorTypeTryingToKillHisOwnFigure] = "You are trying to take your figure.\n",
};

void play()
{
    system("clear");
    show_info();

    while (getchar() != '\n')
        ;

    char board[COLS][RAWS] = {
        {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'4', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, {'1', '|', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'}, {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};

    Move* white = malloc(sizeof(*white));
    Move* black = malloc(sizeof(*black));
    white->color = MoveColorWhite;
    black->color = MoveColorBlack;
    white->current_color_msg = "White: ";
    black->current_color_msg = "Black: ";
    ErrorType err = ErrorTypeNone;

    int moves_count = 1;
    while (1)
    {
        system("clear");
        print_board(board);
        printf("%s", ErrorMsg[(int)err]);
        Move* curMove = (moves_count % 2 == 0) ? black : white;
        printf("%s", curMove->current_color_msg);
        char* inp = get_input();
        err = try_make_move(board, curMove, inp);
        if (err != 0)
            continue;
        change_board(board, curMove);
        ++moves_count;
        free(inp);
    }

    free(white);
    free(black);
}
