#include <libchessviz/cli_interface.h>
#include <stdio.h>
#include <stdlib.h>

#define BLACK_BG "\033[47m"
#define WHITE_BG "\033[40m"
#define DEFAULT "\033[0m"

void show_info()
{
    printf("┌──────────────────────────────────────────────────────────┐\n");
    printf("│                          Rules                           │\n");
    printf("│                                                          │\n");
    printf("│ 1. When you enter the figures are not specified.         │\n");
    printf("│ 2. Case doesn't matter.                                  │\n");
    printf("│ 3. Blacks on top, Whites on bottom.                      │\n");
    printf("│                                                          │\n");
    printf("│                         Examples                         │\n");
    printf("│                                                          │\n");
    printf("│ 1. Take move E4xE2.                                      │\n");
    printf("│ 2. Motion move E4-E2.                                    │\n");
    printf("│                                                          │\n");
    printf("│                        Press Enter                       │\n");
    printf("└──────────────────────────────────────────────────────────┘\n");
}

const char* figures_sprites[] = {
    ['p'] = "♙", ['P'] = "♟", ['r'] = "♖", ['R'] = "♜", ['n'] = "♘", ['N'] = "♞",
    ['b'] = "♗", ['B'] = "♝", ['q'] = "♕", ['Q'] = "♛", ['k'] = "♔", ['K'] = "♚",
};

static void set_color(char* color)
{
    printf("%s", color);
}

void print_board(char board[11][11])
{
    int cols = 8;
    int raws = 10;
    printf("  ┌──────────────────┐\n");
    int color_index = 2;
    for (int i = 0; i < cols; ++i)
    {
        printf("%d │ ", cols - i);
        for (int j = 2; j < raws; ++j)
        {
            set_color(color_index % 2 ? WHITE_BG : BLACK_BG);
            if (board[i][j] == ' ')
                printf("  ");
            else
                printf("%s ", figures_sprites[(int)board[i][j]]);
            set_color(DEFAULT);
            ++color_index;
        }
        color_index++;
        printf(" ");
        printf("│");
        printf("\n");
    }
    printf("  └──────────────────┘\n    ");
    for (int i = 0; i < 8; i++)
        printf("%c ", 'A' + i);
    printf("\n");
}
