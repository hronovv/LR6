#include <iostream>
#include <sstream>
#include <string>
#include <gtest/gtest.h>
long long countFiveDigitGroups(char* input) {
    int i;
    int count = 0;
    int groupLength = 0;
    bool inGroup = false;
    for (i = 0; i < strlen(input); ++i) {
        if (input[i] == '0' || input[i] == '1') {
            if (!inGroup) {
                inGroup = true;
                groupLength = 1;
            } else {
                groupLength++;
            }
        } else {
            if (inGroup) {
                if (groupLength == 5) {
                    count++;
                }
                inGroup = false;
                groupLength = 0;
            }
        }
    }
    if (inGroup && groupLength == 5) {
        count++;
    }
    return count;
}
TEST(count_five_digits1, five_digits) {
    char *input =  "111 000 111 11111";
    ASSERT_EQ(1,countFiveDigitGroups(input));
}
TEST(count_five_digits2, five_digits) {
    char *input =  "";
    ASSERT_EQ(0,countFiveDigitGroups(input));
}
TEST(count_five_digits3, five_digits) {
    char *input =  "1111 0    ";
    ASSERT_EQ(0,countFiveDigitGroups(input));
}
TEST(count_five_digits4, five_digits) {
    char *input =  "111   1111   11111 01011 00111";
    ASSERT_EQ(3,countFiveDigitGroups(input));
}
TEST(count_five_digits5, five_digits) {
    char *input =  "1 0 10 1 000 000 11100 00000 00000 00000 11111      00110";
    ASSERT_EQ(6,countFiveDigitGroups(input));
}
TEST(count_five_digits6, five_digits) {
    char *input =  "111111111111111111111111111111111111111111111111111111";
    ASSERT_EQ(0,countFiveDigitGroups(input));
}
TEST(count_five_digits7, five_digits) {
    char *input =  "0001110000 00110 01011 11100 00000000000";
    ASSERT_EQ(3,countFiveDigitGroups(input));
}
TEST(count_five_digits8, five_digits) {
    char *input =  "                            ";
    ASSERT_EQ(0,countFiveDigitGroups(input));
}
TEST(count_five_digits9, five_digits) {
    char *input =  "10101";
    ASSERT_EQ(1,countFiveDigitGroups(input));
}
TEST(count_five_digits10, five_digits) {
    char *input =  "10010101001001 101001011 00000 00 0 0 0 00000 101111";
    ASSERT_EQ(2,countFiveDigitGroups(input));
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}