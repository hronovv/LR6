#include <iostream>
const int max_length = 81;
const int max_letters_answer = 4;
class stroka {
public:
    int i;
    char* input = new char[max_length];
    char ch;
    char *answer = new char[max_letters_answer];
    private:
    void initializator() {
        while (true) {
            std::cout << "Введите строку (максимум 80 символов, только 0, 1 и пробелы): ";
            i = 0;
            char ch;
            bool validInput = true;
            while (i < max_length - 1 && (ch = getchar()) != '\n' && ch != EOF) {
                if (ch != '0' && ch != '1' && ch != ' ') {
                    validInput = false;
                    break;
                }
                input[i++] = ch;
            }
            if (!validInput) {
                std::cout << "Ошибка: вводить можно только 0, 1 и пробелы. Попробуйте снова." << std::endl;
                while (getchar() != '\n');
                continue;
            }
            input[i] = '\0';
            break; 
        }   
    }
    void countFiveDigitGroups() {
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
    std::cout << "Количество групп из пяти цифр: " << count << std::endl;
    }
    void del() {
        delete[] input;
    }
    public:
    void program() {
        std::cout << "Хотите начать?: ";
        i = 0;
            while (i < max_length - 1 && (ch = getchar()) != '\n' && ch != EOF) {
                answer[i++] = ch;
            }
            answer[i] = '\0';
        while (true) {
            if (strcmp(answer, "да") == 0 || strcmp(answer, "ДА") == 0 || strcmp(answer, "Да") == 0 || strcmp(answer, "дА") == 0 || strcmp(answer, "yes") == 0) {
                initializator();
                countFiveDigitGroups();
                del();
                std::cout << "Хотите еще раз?: ";
                i = 0;
                while (i < max_length - 1 && (ch = getchar()) != '\n' && ch != EOF) {
                    answer[i++] = ch;
                }
                answer[i] = '\0';
            } else if (strcmp(answer, "нет") == 0 || strcmp(answer, "Нет") == 0 || strcmp(answer, "НЕТ") == 0 || strcmp(answer, "no") == 0 || strcmp(answer, "NO") == 0) {
                std::cout << "\nПрограмма успешно завершена!";
                break;
            } else {
                std::cout << "\nВведенное значение неправильное. Введите его заного.\n";
                std::cout << "Хотите еще раз?: ";
                i = 0;
                while (i < max_length - 1 && (ch = getchar()) != '\n' && ch != EOF) {
                    answer[i++] = ch;
                }
                answer[i] = '\0';
            }
        }
    }
};
int main() {
    stroka str;
    str.program();
    return 0;
}