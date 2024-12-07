#include <iostream>
#include <cwchar>
#include <locale>
#include <limits>
const int max_str_length = 2000;
const int max_letters_answer = 8;
class Stroka {
public:
    int i;
    char ch;
    int words_count;
    int word_cost;
    bool inWord;
    char *answer;
    wchar_t* input;
    Stroka(): i(0),ch('\0'),words_count(0),word_cost(0),inWord(false) {
        answer = new char[max_letters_answer];
        input = new wchar_t[max_str_length];
    }
    void getstr() {
        std::wcout << L"Введите текст:\n";
        std::wcin.getline(input, max_str_length);
    }
    ~Stroka() {
        delete[] input;
        delete[] answer;
    }
    void word_count() {
        words_count = 0;
        inWord = false;
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
    }
    void cost_word() {
        std::wcout << L"Введите стоимость одного слова: ";
        std::cin >> word_cost;
        while (true) {
            if (std::cin.peek() == '\n') {
                break;
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\nВведенное значение неправильное. Введите его заного.\n\n";
                std::wcout << L"Введите стоимость одного слова: ";
                std::cin >> word_cost;
            }
        }
    }
    void print_cost() {
        cost_word();
        word_count();
        std::wcout << L"Стоимость текста: " << words_count*word_cost << std::endl;
    }
    public:
    void program() {
        std::cout << "Хотите начать? (да/нет): ";
        i = 0;
        while (i < max_letters_answer - 1 && (ch = getchar()) != '\n' && ch != EOF) {
            answer[i++] = ch;
        }
        while (ch != '\n' && ch != EOF) {
            ch = getchar();
        }
        answer[i] = '\0';
        while (true) {
            if (strcmp(answer, "да") == 0 || strcmp(answer, "ДА") == 0 || strcmp(answer, "Да") == 0 || strcmp(answer, "дА") == 0 || strcmp(answer, "yes") == 0) {
                getstr();
                print_cost();
                std::cout << "Хотите еще раз? (да/нет): ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                i = 0;
                while (i < max_letters_answer - 1 && (ch = getchar()) != '\n' && ch != EOF) {
                    answer[i++] = ch;
                }
                while (ch != '\n' && ch != EOF) {
                    ch = getchar();
                }
                answer[i] = '\0';
            } else if (strcmp(answer, "нет") == 0 || strcmp(answer, "Нет") == 0 || strcmp(answer, "НЕТ") == 0 || strcmp(answer, "no") == 0 || strcmp(answer, "NO") == 0) {
                std::cout << "\nПрограмма успешно завершена!";
                break;
            } else {
                std::cout << "\nВведенное значение неправильное. Введите его заного.\n";
                std::cout << "Хотите еще раз? (да/нет): ";
                i = 0;
                while (i < max_letters_answer - 1 && (ch = getchar()) != '\n' && ch != EOF) {
                    answer[i++] = ch;
                }
                while (ch != '\n' && ch != EOF) {
                    ch = getchar();
                }
                answer[i] = '\0';
            }
        }
    }
};
int main() {
    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcout.imbue(std::locale("ru_RU.UTF-8")); 
    Stroka stroka;
    stroka.program();
    return 0;
}