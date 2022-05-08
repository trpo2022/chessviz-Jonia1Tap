#include <ctest.h>
#include <libchessviz/string_parser.h>

CTEST(string_parser, convert_string_to_lower_should_return_string_in_lower_register)
{
    char given[] = "ASDFGH";
    char expected[] = "asdfgh";
    tolower_string(given);
    ASSERT_STR(expected, given);
}

CTEST(string_parser, validate_correct_coordinates_should_return_true)
{
    for (int i = 0; i < 8; ++i)
    {
        char x = 'a' + i;
        char y = '1' + i;
        ASSERT_TRUE(is_valid_coords(x, y));
    }
}

CTEST(string_parser, validate_incorrect_coordinates_should_return_false)
{
    char x = 'k';
    char y = '1';
    ASSERT_FALSE(is_valid_coords(x, y));
}

CTEST(string_parser, validate_correct_move_type_should_return_true)
{
    char motion = '-';
    char take = 'x';
    ASSERT_TRUE(is_valid_move_type(motion));
    ASSERT_TRUE(is_valid_move_type(take));
}

CTEST(string_parser, validate_incorrect_move_type_should_return_false)
{
    char motion = '=';
    char take = '*';
    ASSERT_FALSE(is_valid_move_type(motion));
    ASSERT_FALSE(is_valid_move_type(take));
}

CTEST(string_parser, parse_correct_input_should_return_error_none)
{
    char given_motion[] = "a2-a4\n";
    Move move;
    ASSERT_EQUAL(ErrorTypeNone, try_parse_input(&move, given_motion));
    ASSERT_EQUAL(MoveTypeMotion, move.type_move);
    ASSERT_EQUAL(2, move.x1);
    ASSERT_EQUAL(2, move.x2);
    ASSERT_EQUAL(6, move.y1);
    ASSERT_EQUAL(4, move.y2);

    char given_take[] = "a2xa4\n";
    ASSERT_EQUAL(ErrorTypeNone, try_parse_input(&move, given_take));
    ASSERT_EQUAL(MoveTypeTake, move.type_move);
    ASSERT_EQUAL(2, move.x1);
    ASSERT_EQUAL(2, move.x2);
    ASSERT_EQUAL(6, move.y1);
    ASSERT_EQUAL(4, move.y2);
}

CTEST(string_parser, parse_empty_should_return_error_incorrect_input)
{
    char given[] = "";
    Move move;
    ASSERT_EQUAL(ErrorTypeIncorrectInput, try_parse_input(&move, given));
}

CTEST(string_parser, parse_incorrect_length_should_return_error_incorrect_input)
{
    char given[] = "qwertyu";
    Move move;
    ASSERT_EQUAL(ErrorTypeIncorrectInput, try_parse_input(&move, given));
}

CTEST(string_parser, parse_incorrect_move_type_should_return_error_wrong_move)
{
    char given[] = "e2_e4\n";
    Move move;
    ASSERT_EQUAL(ErrorTypeWrongMoveType, try_parse_input(&move, given));
}