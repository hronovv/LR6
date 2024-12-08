#include <gtest/gtest.h>
#include <iostream>
#include <cwchar>
#include <locale>
#include <sstream>
#include <string>
std::string reverse_word(char* input,long long sum = 0) {
    std::ostringstream str;
    for (int i = 0; i < strlen(input); ++i) {
        sum += static_cast<int>(input[i]);
    }
    if (sum%2 == 1) {
        for (int i = 0; i < strlen(input); ++i) {
            str << input[i] << "";
        }
    } else {
        for (int i = 0; i < strlen(input); ++i) {
            str << input[strlen(input)-i-1] << "";
        }
    }
    return str.str();
}
TEST(reverse_word1,reverse__word) {
    char* input = "hello";
    ASSERT_EQ("olleh",reverse_word(input));
}
TEST(reverse_word2,reverse__word) {
    char* input = "cba";
    ASSERT_EQ("abc",reverse_word(input));
}
TEST(reverse_word3,reverse__word) {
    char* input = "";
    ASSERT_EQ("",reverse_word(input));
}
TEST(reverse_word4,reverse__word) {
    char* input = "xyz";
    ASSERT_EQ("xyz",reverse_word(input));
}
TEST(reverse_word5,reverse__word) {
    char* input = "C++ Programming";
    ASSERT_EQ("gnimmargorP ++C",reverse_word(input));
}
TEST(reverse_word6,reverse__word) {
    char* input = "aaaaaaaaaaaaaaaaaaaaaab";
    ASSERT_EQ("baaaaaaaaaaaaaaaaaaaaaa",reverse_word(input));
}
TEST(reverse_word7,reverse__word) {
    char* input = "ivanivanivan";
    ASSERT_EQ("navinavinavi",reverse_word(input));
}
TEST(reverse_word8,reverse__word) {
    char* input = "123 456";
    ASSERT_EQ("123 456",reverse_word(input));
}
TEST(reverse_word9,reverse__word) {
    char* input = "heLlo World 888";
    ASSERT_EQ("888 dlroW olLeh",reverse_word(input));
}
TEST(reverse_word10,reverse__word) {
    char* input = "1";
    ASSERT_EQ("1",reverse_word(input));
}
int main(int argc, char** argv) {
    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcout.imbue(std::locale("ru_RU.UTF-8")); 
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}