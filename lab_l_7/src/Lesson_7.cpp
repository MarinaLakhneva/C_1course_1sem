#pragma warning(disable:4996) // Отключает предупреждения об устаревших функциях типа printf и scanf
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <locale.h> // ипользуется для распознавания русского языка

void PrintInt(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void PrintDouble(double b[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%f ", b[i]);
    }
    printf("\n");
}

void FillInt(int a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = 600 + i * 2;
    }
    PrintInt(a, size);
}

void FillDouble(double b[], int size) {
    for (int i = 0; i < size; i++) {
        b[i] = 600 + i * 2;
    }
    PrintDouble(b, size);
}

void MemoryDump(unsigned char* ptr, int size) {
    int i = 0;

    for (unsigned char* p = ptr; p != ptr + size; ++p) {
        if (i % 16 == 0) {
            printf("%p:", p); // вывод адреса
        }
        printf("%02X ", *p); //вывод срдержимого по этому адресу
        i++;
        if (i % 16 == 0) {
            printf("\n");
        }
        //printf("%02X ", *p);
    }
    puts("");
}

int main() {
    setlocale(LC_CTYPE, "Russian"); // ипользуется для распознавания русского языка (LC_ALL - не использовать)
    const int N = 9;

    int a[N] = { 0 }; //Создаем массив
    FillInt(a, N); // Заполняем его значениями
    //int* A = &a[0]; // мы создаем указатель на данные типа int и записываем в него адрес первого элемента массива a
    MemoryDump((unsigned char*)&a, sizeof a);

    printf("\n");

    double b[N] = { 0 }; //Создаем массив
    FillDouble(b, N); // Заполняем его значениями
    //double* B = &b[0]; // мы создаем указатель на данные типа double и записываем в него адрес первого элемента массива b
    MemoryDump((unsigned char*)&b, sizeof b);
    return 0;
}