#pragma warning(disable:4996)

#include <stddef.h> // NULL
#include <stdio.h>  
#include <stdlib.h> // malloc
#include <locale.h>

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

char* Reverse(const char* str) {
    int length = GetLengthStr(str);

    char* revStr = (char*)malloc(length + 1);

    if (revStr == NULL)
        return NULL;

    int j = 0;
    for (int i = (length - 1); i >= 0; --i) {
        if (str[i] != '\n') {
            revStr[j] = str[i];
            j++;
        }
    }
    revStr[j] = '\0';
    return revStr;
}

int main(void) {
    setlocale(LC_CTYPE, "Russian");

    printf("Задание STR–1: Разворот строк\n");

    const int N = 100;
    char buf[N] = "\0";

    while (1) {
        printf("%-14s: ", "Введите строку");

        char* src = fgets(buf, N, stdin);

        if (src == NULL || *src == '\n')
            break;

        char* dst = Reverse(buf);

        printf("%-14s: ", "Результат");
        printf("%s\n", dst);

        free(dst);
    }
    return 0;
}