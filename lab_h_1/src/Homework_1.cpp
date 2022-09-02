#pragma warning(disable:4996)

#include <stddef.h> // NULL
#include <stdio.h>  
#include <stdlib.h> // malloc
#include <locale.h>
#include <math.h>   // pow

typedef unsigned char integer_t;
//typedef unsigned short integer_t;
//typedef unsigned int integer_t;
//typedef unsigned long integer_t;
typedef unsigned long maxInt_t;


int* TransferTo2(integer_t value, int size) {
    int* arr = (int*)malloc(size * 8 * sizeof(int));

    if (arr == NULL) {
        return NULL;
    }

    for (int i = size * 8 - 1; i >= 0; --i) {
        arr[i] = value & (1 << i) ? 1 : 0;
    }
    return arr;
}

integer_t TransferTo10(const int* arr, int size) {
    integer_t value = 0;

    for (int i = 0; i < size * 8; ++i) {
        if (arr[i] != 0)
            value += pow(2, i);
    }
    return value;
}

integer_t Process(integer_t value) {
    int* arr = TransferTo2(value, sizeof(integer_t));

    for (int i = 0, k = sizeof(integer_t) * 8 - 1; i < k; ++i, --k) {
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
    integer_t convValue = TransferTo10(arr, sizeof(integer_t));

    free(arr);
    return convValue;
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    printf("Задание BIT–1: Реверс битов\n");

    while (1) {
        maxInt_t input;
        printf("%-13s: ", "Введите число");
        if (scanf("%u", &input) == 0)
            break;

        integer_t src;
        src = input;
        int* bitSrc = TransferTo2(src, sizeof(integer_t));

        integer_t dst;
        dst = Process(src);
        int* bitDst = TransferTo2(dst, sizeof(integer_t));

        printf("%-13s: %*u = 0x%0*X = ", "Вы ввели", sizeof(integer_t) * 3, src, sizeof(integer_t) * 2, src);
        for (int i = sizeof(integer_t) * 8 - 1; i >= 0; --i)
            printf("%i", bitSrc[i]);
        printf("\n");

        printf("%-13s: %*u = 0x%0*X = ", "Результат", sizeof(integer_t) * 3, dst, sizeof(integer_t) * 2, dst);
        for (int i = sizeof(integer_t) * 8 - 1; i >= 0; --i)
            printf("%i", bitDst[i]);
        printf("\n");

        free(bitSrc);
        free(bitDst);

        if (src == 0) {
        break;
        }
    }
    return 0;
}