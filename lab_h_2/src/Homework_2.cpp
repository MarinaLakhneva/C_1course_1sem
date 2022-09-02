#pragma warning(disable:4996) // Отключает предупреждения об устаревших функциях типа printf и scanf
#include <ctype.h>      // isalnum
#include <locale.h>
#include <stdbool.h>    // bool
#include <stddef.h>     // NULL
#include <stdio.h>      // getchar
#include <stdlib.h>     // realloc

int GetLengthStr(const char* str) {
    if (str == NULL) {
        return 0;
    }

    int size = 0;
    while (str[size] != '\0') {
        size++;
    }
    return size;
}

void CopyStr(char* variable, const char* constant) {
    int begin = GetLengthStr(variable);
    int i = 0;

    while (constant[i] != '\0') {
        variable[begin + i] = constant[i];
        i++;
    }
    variable[begin + i] = '\0';
}

char* ReadLine(void) {
    char* line = NULL;
    char* temp = NULL;

    int size = 0;
    int ch;
    while ((ch = getchar()) != '\n') {
        size++;

        temp = (char*)realloc(line, size + 1);
        if (!temp) {
            free(line);
            return NULL;
        }
        line = temp;
        line[size - 1] = ch;
    }

    if (size != 0) {
        line[size] = '\0';
    }
    return line;
}

char* ReadParagraph(void) {
    char* paragraph = NULL;
    char* line = NULL;
    char* temp = NULL;

    while (line = ReadLine()) {
        if (!paragraph) {
            temp = (char*)realloc(paragraph, GetLengthStr(paragraph) + GetLengthStr(line) + 1);

            if (!temp) {
                free(paragraph);
                free(line);
                return NULL;
            }
            paragraph = temp;
            paragraph[0] = '\0';
        }
        else {
            temp = (char*)realloc(paragraph, GetLengthStr(paragraph) + GetLengthStr(line) + 1 + 1);

            if (!temp) {
                free(paragraph);
                free(line);
                return NULL;
            }
            paragraph = temp;

            int size = GetLengthStr(paragraph);
            paragraph[size] = ' ';
            paragraph[size + 1] = '\0';
        }
        CopyStr(paragraph, line);
    }
    return paragraph;
}

char* ExtractWords(char const* str) {
    char* line = NULL;
    char* temp = NULL;
    int size = 0;
    bool isWord = false;

    int ch;
    int i = 0;
    while ((ch = str[i]) != '\0') {
        if (isalnum(ch)) {
            if (isWord) {
                size += 2;

                temp = (char*)realloc(line, size + 1);
                if (!temp) {
                    free(line);
                    return NULL;
                }
                line = temp;
                line[size - 2] = ',';
                line[size - 1] = ' ';

                isWord = false;
            }
            ++size;

            temp = (char*)realloc(line, size + 1);
            if (!temp) {
                free(line);
                return NULL;
            }
            line = temp;
            line[size - 1] = ch;
        }
        else {
            isWord = true;
        }
        ++i;
    }

    if (size != 0) {
        line[size] = '\0';
    }
    return line;
}


int main(void) {
    setlocale(LC_CTYPE, "Russian");

    printf("%-20s: ", "Введите строку");
    char* src = ReadParagraph();

    printf("%-20s: ", "Промежуточная строка");
    printf("%s\n", src);

    printf("%-20s: ", "Результат");
    char* dst = ExtractWords(src);
    printf("%s", dst);

    free(src);
    free(dst);
    return 0;
}