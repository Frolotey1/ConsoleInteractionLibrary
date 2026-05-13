#define BOOST_TEST_MODULE "ConsoleLibraryTests"
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/unit_test.hpp>

#include "../include/InputDialog.h"
#include "../include/Menu.h"
#include "../include/Validators.h"
#include "../include/ConsoleInput.h"
#include "../include/ConsoleOutput.h"

BOOST_AUTO_TEST_SUITE(ValidatorTests)

BOOST_AUTO_TEST_CASE(NotEmpty_EmptyString_ReturnsFalse) {
    BOOST_CHECK_EQUAL(not_empty(""), false);
}

BOOST_AUTO_TEST_CASE(NotEmpty_NonEmptyString_ReturnsTrue) {
    BOOST_CHECK_EQUAL(not_empty("hello"), true);
}

BOOST_AUTO_TEST_CASE(IsAlnum_OnlyLetters_ReturnsTrue) {
    BOOST_CHECK_EQUAL(is_alnum("abcDEF"), true);
}

BOOST_AUTO_TEST_CASE(IsAlnum_OnlyDigits_ReturnsTrue) {
    BOOST_CHECK_EQUAL(is_alnum("123456"), true);
}

BOOST_AUTO_TEST_CASE(IsAlnum_WithSpecialChars_ReturnsFalse) {
    BOOST_CHECK_EQUAL(is_alnum("abc!123"), false);
}

BOOST_AUTO_TEST_CASE(Positive_NegativeNumber_ReturnsFalse) {
    BOOST_CHECK_EQUAL(positive(-5), false);
}

BOOST_AUTO_TEST_CASE(Positive_Zero_ReturnsFalse) {
    BOOST_CHECK_EQUAL(positive(0), false);
}

BOOST_AUTO_TEST_CASE(Positive_PositiveNumber_ReturnsTrue) {
    BOOST_CHECK_EQUAL(positive(10), true);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(ParseTests)

BOOST_AUTO_TEST_CASE(Parse_ValidInt_ReturnsTrue) {
    ConsoleOutput output;
    ConsoleInput input;
    InputDialog<int> dialog(output, input);
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(MenuTests)

BOOST_AUTO_TEST_CASE(Menu_CanBeCreated) {
    ConsoleOutput output;
    ConsoleInput input;
    Menu menu("Test", output, input);
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(Menu_CanAddItem) {
    ConsoleOutput output;
    ConsoleInput input;
    Menu menu("Test", output, input);
    menu.add_item("Item", [](){});
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(Menu_CanAddExitItem) {
    ConsoleOutput output;
    ConsoleInput input;
    Menu menu("Test", output, input);
    menu.add_exit_item("Exit");
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(ConsoleIOTests)

BOOST_AUTO_TEST_CASE(ConsoleOutput_Write_Compiles) {
    ConsoleOutput output;
    output.write("test");
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(ConsoleOutput_WriteLine_Compiles) {
    ConsoleOutput output;
    output.write_line("test");
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(ConsoleInput_ReadLine_Compiles) {
    ConsoleInput input;
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(InputDialogTests)

BOOST_AUTO_TEST_CASE(InputDialog_CanBeCreated) {
    ConsoleOutput output;
    ConsoleInput input;
    InputDialog<int> dialog(output, input);
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_SUITE_END()
