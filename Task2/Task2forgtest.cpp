#include <gtest/gtest.h>
#include <iostream>
#include <cwchar>
#include <locale>
long long word_count(wchar_t* input, long long price) {
    long long words_count = 0;
    bool inWord = false;
    for (int i = 0; i < wcslen(input); ++i) { 
        if (std::iswalnum(input[i])) {
            if (!inWord) {
                inWord = true; 
                words_count++; 
            } 
        } else if (std::iswspace(input[i])) { 
            inWord = false;
        } 
    }
    return words_count*price;
}
TEST(count_words_price1,word_price) {
    wchar_t* input = L"ваыа вы ав аыв";
    long long price = 17;
    ASSERT_EQ(68, word_count(input,price));
}
TEST(count_words_price2,word_price) {
    wchar_t* input = L"";
    long long price = 17291399292391;
    ASSERT_EQ(0, word_count(input,price));
}
TEST(count_words_price3,word_price) {
    wchar_t* input = L"fklmdaskmldsakmlsadkmldasmklsdkmldsakmlmdklamkdlsmkdmkl";
    long long price = 99;
    ASSERT_EQ(99, word_count(input,price));
}
TEST(count_words_price4,word_price) {
    wchar_t* input = L"один два три четыре пять шесть семь";
    long long price = 0;
    ASSERT_EQ(0, word_count(input,price));
}
TEST(count_words_price5,word_price) {
    wchar_t* input = L"я вчера покушал курицу";
    long long price = 7;
    ASSERT_EQ(28, word_count(input,price));
}
TEST(count_words_price6,word_price) {
    wchar_t* input = L"babyshka бабушка chislo число";
    long long price = 9999;
    ASSERT_EQ(39996, word_count(input,price));
}
TEST(count_words_price7,word_price) {
    wchar_t* input = L"никогда бы не подумал но на самом деле            ";
    long long price = 12;
    ASSERT_EQ(96, word_count(input,price));
}
TEST(count_words_price8,word_price) {
    wchar_t* input = L"          ";
    long long price = 1000000000000000;
    ASSERT_EQ(0, word_count(input,price));
}
TEST(count_words_price9,word_price) {
    wchar_t* input = L"пушка";
    long long price = 1;
    ASSERT_EQ(1, word_count(input,price));
}
TEST(count_words_price10,word_price) {
    wchar_t* input = L"кушать. точка. нельзя. ";
    long long price = 3;
    ASSERT_EQ(9, word_count(input,price));
}
int main(int argc, char** argv) {
    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcout.imbue(std::locale("ru_RU.UTF-8")); 
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}