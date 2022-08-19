#pragma warning(disable:4996) // Отключает предупреждения об устаревших функциях типа printf и scanf
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h> // ипользуется для распознавания русского языка

int main() {
	setlocale(LC_CTYPE, "Russian"); // ипользуется для распознавания русского языка (LC_ALL - не использовать)
    int N = 50;

    int* m;  // указатель на массив 
    m = (int*)malloc(N * sizeof(int));

    int divisible = 0;
    int divider = 0;

    int entire = 0; // целое
    int remains = 0; // остаток

    int value = 2;
    for (int i = 1; i < N; i++) {
        m[0] = 2;

        divisible = 0;
        divider = 0;

        value = 2 * value + entire;
        entire = 0;

        if (value < 10) {
            m[i] = value;
            if (m[i] == 2) { // 105 263 157 894 736 842
                for (int k = (i - 1); k > -1; k--) {
                    printf("%i", m[k]);
                }
                break;
            }
        }
        else {
            entire = 0;
            entire = value / 10; // целое 1
            remains = value % 10; // остаток 6
            m[i] = remains;
            value = remains;
        }
        //for (size_t c = 0; c < (i + 1); c++) { // ломается на значении 894 736 842
        //    divider += pow(10, (c + 1)) * m[c];
        //}
        //divider = divider + 2;

        //int count = 0;
        //for (size_t c = 0; c < (i + 1); c++) {
        //    divisible += pow(10, c) * m[c];
        //    count++;
        //}
        //divisible = divisible + 2 * pow(10, count);
    }
    return 0;
}
