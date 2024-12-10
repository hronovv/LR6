#include <iostream>
#include <cwchar>
#include <locale>
#include <locale.h>
#include <limits>
const int max_str_length = 2000;
const int max_letters_answer = 8;
const int max_matrix_size = 100;
class Stroka {
public:
    wchar_t matrix[max_matrix_size][max_str_length];
    int rows;
    int cols;
    int i;
    wchar_t ch;
    wchar_t *answer;
    Stroka() : rows(0), cols(0), i(0), ch(L'\0') {
        answer = new wchar_t[max_letters_answer];
        for (int i = 0; i < max_matrix_size; ++i) {
            matrix[i][0] = L'\0';
        }
    }
    ~Stroka() {
        delete[] answer;
    }
    void input_matrix() {
        std::wcout << L"Введите количество строк матрицы: ";
        std::wcin >> rows;
        while (true) {
            if (rows > 0) {
                if (std::wcin.peek() == L'\n') {
                    break;
                } else {
                    std::wcin.clear();
                    std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
                    std::wcout << L"\nВведенное значение неправильное. Введите его заново.\n\n";
                    std::wcout << L"Введите количество строк матрицы: ";
                    std::wcin >> rows;
                }
            } else {
                std::wcin.clear();
                std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
                std::wcout << L"\nВведенное значение неправильное. Введите его заново.\n\n";
                std::wcout << L"Введите количество строк матрицы: ";
                std::wcin >> rows;
            }
        }
        std::wcout << L"Введите количество столбцов матрицы: ";
        std::wcin >> cols;
        while (true) {
            if (cols > 0) {
                if (std::wcin.peek() == L'\n') {
                    break;
                } else {
                    std::wcin.clear();
                    std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
                    std::wcout << L"\nВведенное значение неправильное. Введите его заново.\n\n";
                    std::wcout << L"Введите количество столбцов матрицы: ";
                    std::wcin >> cols;
                }
            } else {
                std::wcin.clear();
                std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
                std::wcout << L"\nВведенное значение неправильное. Введите его заново.\n\n";
                std::wcout << L"Введите количество столбцов матрицы: ";
                std::wcin >> cols;
            }
        }
        std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
        for (int i = 0; i < rows; ++i) {
            std::wcout << L"Введите строку " << i + 1 << L": ";
            std::wcin.getline(matrix[i], max_str_length);
        }
    }
    int sum_of_codes(const wchar_t* word) {
        int sum = 0;
        for (int i = 0; word[i] != L'\0'; ++i) {
            sum += static_cast<int>(word[i]);
        }
        return sum;
    }
    void reverse_word(wchar_t* word) {
        int len = std::wcslen(word);
        wchar_t* buffer = new wchar_t[len + 1]; 
        for (int i = 0; i < len; ++i) {
            buffer[i] = word[len - 1 - i];
        }
        buffer[len] = L'\0'; 
        std::wcsncpy(word, buffer, len + 1); 
        delete[] buffer; 
    } 
    void process_matrix() {
        wchar_t word[max_str_length];
        for (int i = 0; i < rows; ++i) {
            int index = 0;
            for (int j = 0; matrix[i][j] != L'\0'; ++j) {
                if (std::iswspace(matrix[i][j])) {
                    if (index > 0) {
                        word[index] = L'\0';
                        if (sum_of_codes(word) % 2 == 0) {
                            reverse_word(word);
                        }
                        std::wcout << word << L" ";
                        index = 0;
                    }
                    std::wcout << matrix[i][j];
                } else {
                    word[index++] = matrix[i][j];
                }
            }
            if (index > 0) {
                word[index] = L'\0';
                if (sum_of_codes(word) % 2 == 0) {
                    reverse_word(word);
                }
                std::wcout << word;
            }
            std::wcout << std::endl;
        }
    }
    void program() {
        std::wcout << L"Хотите начать? (да/нет): ";
        i = 0;
        while (i < max_letters_answer - 1 && (ch = std::getwchar()) != L'\n' && ch != WEOF) {
            answer[i++] = ch;
        }
        while (ch != L'\n' && ch != WEOF) {
            ch = std::getwchar();
        }
        answer[i] = L'\0';
        while (true) {
            if (std::wcscmp(answer, L"да") == 0 || std::wcscmp(answer, L"ДА") == 0 || std::wcscmp(answer, L"Да") == 0 || std::wcscmp(answer, L"дА") == 0 || std::wcscmp(answer, L"yes") == 0) {
                input_matrix();
                process_matrix();
                std::wcout << L"Хотите еще раз? (да/нет): ";
                i = 0;
                while (i < max_letters_answer - 1 && (ch = std::getwchar()) != L'\n' && ch != WEOF) {
                    answer[i++] = ch;
                }
                while (ch != L'\n' && ch != WEOF) {
                    ch = std::getwchar();
                }
                answer[i] = L'\0';
            } else if (std::wcscmp(answer, L"нет") == 0 || std::wcscmp(answer, L"Нет") == 0 || std::wcscmp(answer, L"НЕТ") == 0 || std::wcscmp(answer, L"no") == 0 || std::wcscmp(answer, L"NO") == 0) {
                std::wcout << L"\nПрограмма успешно завершена!";
                break;
            } else {
                std::wcout << L"\nВведенное значение неправильное. Введите его заново.\n";
                std::wcout << L"Хотите еще раз? (да/нет): ";
                i = 0;
                while (i < max_letters_answer - 1 && (ch = std::getwchar()) != L'\n' && ch != WEOF) {
                    answer[i++] = ch;
                }
                while (ch != L'\n' && ch != WEOF) {
                    ch = std::getwchar();
                }
                answer[i] = L'\0';
            }
        }
    }
};
int main() {
    std::setlocale(LC_ALL, "ru_RU.UTF-8");
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));
    Stroka stroka;
    stroka.program();
    return 0;
}