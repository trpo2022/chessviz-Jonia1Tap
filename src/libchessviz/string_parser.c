#include <ctype.h>
#include <libchessviz/string_parser.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_input()
{
    char* input_buffer = NULL;
    size_t len;
    getline(&input_buffer, &len, stdin);
    return input_buffer;
}

void tolower_string(char* input)
{
    for (int i = 0; i < strlen(input); ++i)
        input[i] = tolower(input[i]);
}

ErrorType try_parse_input(Move* move, char* inp)
{
    if (strlen(inp) != 6)
        return ErrorTypeIncorrectInput;
    tolower_string(inp);
    if (!is_valid_coords(inp[0], inp[1]))
        return ErrorTypeIncorrectInput;
    if (!is_valid_move_type(inp[2]))
        return ErrorTypeWrongMoveType;
    if (!is_valid_coords(inp[3], inp[4]))
        return ErrorTypeIncorrectInput;
    if (inp[0] == inp[3] && inp[1] == inp[4])
        return ErrorTypeIncorrectInput;

    move->x1 = (int)tolower(inp[0]) - 'a' + 2;
    move->y1 = -((int)tolower(inp[1]) - '8');

    move->type_move = (MoveType)inp[2];

    move->x2 = (int)tolower(inp[3]) - 'a' + 2;
    move->y2 = -((int)tolower(inp[4]) - '8');

    return 0;
}