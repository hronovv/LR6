#include <iostream>
#include <cstring>
#include <limits>

const int max_str_length = 2000;
const int max_letters_answer = 8;
const int max_matrix_size = 100;

class Stroka {
public:
    char matrix[max_matrix_size][max_str_length];
    int rows;
    int cols;
    int i;
    char ch;
    char *answer;
    Stroka() : rows(0), cols(0), i(0), ch('\0') {
        answer = new char[max_letters_answer];
        for (int i = 0; i < max_matrix_size; ++i) {
            matrix[i][0] = '\0';
        }
    }

    ~Stroka() {
        delete[] answer;
    }
    void input_matrix() {
        std::cout << "Введите количество строк матрицы: ";
        std::cin >> rows;
        while (true) {
            if (rows > 0) {
                if (std::cin.peek() == '\n') {
                    break;
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\nВведенное значение неправильное. Введите его заново.\n\n";
                    std::cout << "Введите количество строк матрицы: ";
                    std::cin >> rows;
                }
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\nВведенное значение неправильное. Введите его заново.\n\n";
                std::cout << "Введите количество строк матрицы: ";
                std::cin >> rows;
            }
        }
        std::cout << "Введите количество столбцов матрицы: ";
        std::cin >> cols;
        while (true) {
            if (cols > 0) {
                if (std::cin.peek() == '\n') {
                    break;
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\nВведенное значение неправильное. Введите его заново.\n\n";
                    std::cout << "Введите количество столбцов матрицы: ";
                    std::cin >> cols;
                }
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\nВведенное значение неправильное. Введите его заново.\n\n";
                std::cout << "Введите количество столбцов матрицы: ";
                std::cin >> cols;
            }
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        for (int i = 0; i < rows; ++i) {
            std::cout << "Введите строку " << i + 1 << ": ";
            std::cin.getline(matrix[i], max_str_length);
        }
    }
    int sum_of_codes(const char* word) {
        int sum = 0;
        for (int i = 0; word[i] != '\0'; ++i) {
            sum += static_cast<int>(word[i]);
        }
        return sum;
    }
    void reverse_word(char* word) {
        int len = std::strlen(word);
        for (int i = 0; i < len / 2; ++i) {
            std::swap(word[i], word[len - 1 - i]);
        }
    }
    void process_matrix() {
        char word[max_str_length];
        for (int i = 0; i < rows; ++i) {
            int index = 0;
            for (int j = 0; matrix[i][j] != '\0'; ++j) {
                if (std::isspace(matrix[i][j])) {
                    if (index > 0) {
                        word[index] = '\0';
                        if (sum_of_codes(word) % 2 == 0) {
                            reverse_word(word);
                        }
                        std::cout << word << " ";
                        index = 0;
                    }
                    std::cout << matrix[i][j];
                } else {
                    word[index++] = matrix[i][j];
                }
            }
            if (index > 0) {
                word[index] = '\0';
                if (sum_of_codes(word) % 2 == 0) {
                    reverse_word(word);
                }
                std::cout << word;
            }
            std::cout << std::endl;
        }
    }
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
                input_matrix();
                process_matrix();
                std::cout << "Хотите еще раз? (да/нет): ";
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
                std::cout << "\nВведенное значение неправильное. Введите его заново.\n";
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
