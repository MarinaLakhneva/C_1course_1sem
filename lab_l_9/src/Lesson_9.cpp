#pragma warning(disable:4996) // Отключает предупреждения об устаревших функциях типа printf и scanf
#include <locale.h> // ипользуется для распознавания русского языка
#include <stdlib.h> // rand
#include <stddef.h> // NULL
#include <stdio.h>  // printf, fprintf
#include <ctype.h>  // isprint
#include <time.h>   

void FillFloats(float arr[], int length, float a, float b) {
    for (int i = 0; i < length; i++)
        arr[i] = a + ((float)rand() / RAND_MAX) * (b - a);
}

void PrintFloats(float arr[], int length) {
    printf("{");
    for (int i = 0; i < length; i++) {
        printf("%f", arr[i]);
        if (i < (length - 1))
            printf(", ");
    }
    printf("}");
}

void WriteText(char const* filename, float arr[], int length) {
    FILE* textFile;
    textFile = fopen(filename, "wt");

    if (textFile == NULL){
        printf("Не удалось открыть или создать файл.");
        return;
    }

    for (int i = 0; i < length; i++) {
        fprintf(textFile, "%.1f", arr[i]);
        if (i < (length - 1))
            fprintf(textFile, " ");
    }
    fclose(textFile);
}

void WriteBinary(char const* filename, float arr[], int length) {
    FILE* binFile;
    binFile = fopen(filename, "wb");

    if (binFile == NULL) {
        printf("Не удалось открыть или создать файл.");
        return;
    }
    fwrite(arr, sizeof(float), length, binFile);
    fclose(binFile);
}

float* ReadText(char const* filename, int* length) {
    FILE* textFile;
    textFile = fopen(filename, "rt");

    if (textFile == NULL) {
        printf("Не удалось открыть файл.");
        return NULL;
    }

    float* arr = NULL;
    float* buf = NULL;
    float input = 0.0f;
    int count = 0;

    while (fscanf(textFile, "%f", &input) != EOF) {
        count++;
        buf = (float*)realloc(arr, count * sizeof(float));

        if (buf == NULL) {
            free(arr);
            fclose(textFile);
            return NULL;
        }
        arr = buf;
        arr[count - 1] = input;
    }
    *length = count; // в указатель кладем значение (были с этим проблемки)

    fclose(textFile);
    return arr;
}

float* ReadBinary(char const* filename, int* length) {
    FILE* binFile;
    binFile = fopen(filename, "rb");

    if (binFile == NULL) {
        printf("Не удалось открыть файл.");
        return NULL;
    }

    fseek(binFile, 0, SEEK_END);
    int sizeChar = ftell(binFile);
    fseek(binFile, 0, SEEK_SET);

    float* arr = (float*)malloc(sizeChar);

    if (arr == NULL) {
        printf("Не удалось выделить память.");
        return NULL;
    }

    int sizeFloat = sizeChar / sizeof(float);

    *length = fread(arr, sizeof(float), sizeFloat, binFile); //Функция fread() возвращает количество действительно считанных объектов. Если количество считанных объектов меньше, чем это указано при вызове, то либо произошла ошибка, либо был достигнут конец файла.

    if (*length != sizeFloat) { // проверка все ли считали
        printf("Не удалось считать данные.");
        return NULL;
    }
    fclose(binFile);
    return arr;
}

void FileDump(char const* filename) {
    FILE* file;
    file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Не удалось открыть файл.");
        return;
    }

    int code = 0x00;
    int count = 0;
    while ((code = fgetc(file)) != EOF) { // В случае успешного чтения строки, возвращается указатель на массив, в который помещены считанные данные (возвращается аргумент s). Если достигнут конец файла, а данные не были считаны, то возвращается NULL.
        if ((count % 16) == 0) {
            if (count != 0) {
                printf("\n");
            }
            printf("%08X:", ftell(file) - 1); // Функция ftell() возвращает текущее значение указателя положения в файле для указанного потока. Это значение представляет собой количество байт, на которое указатель отстоит от начала файла.
            printf(" ");
        }
        count++;
        printf("%02X", code); // перевод значения в шестнадцатиричное %02X (благодаря X)
        printf(" ");
    }
    fclose(file);
}

void FileDumpPlus(char const* filename) {
    FILE* file;
    file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Не удалось открыть файл.");
        return;
    }

    unsigned char arr[16] = {};
    int size = 0;

    while ((size = fread(arr, sizeof(unsigned char), 16, file)) > 0) {
        printf("%08X:", ftell(file) - size);
        printf(" ");

        for (int i = 0; i < size; i++) {
            printf("%02X", arr[i]);
            if (i < (size - 1))
                printf(" ");
        }

        printf("\t");
        printf("%*", 9);

        for (int i = 0; i < size; i++){
            if (isprint(arr[i])) {
                printf("%c", arr[i]);
            }
            else {
                printf(".");
            }
        }
        printf("\n");
    }
    fclose(file);
}

int main() {
    setlocale(LC_CTYPE, "Russian"); // ипользуется для распознавания русского языка (LC_ALL - не использовать)
    srand(time(NULL));

    int const N = 9;
    float const a = 0;
    float const b = 100;

    char const TEXT_FILE[] = "array.txt";
    char const BIN_FILE[] = "array.bin";

    float arr[N] = {};

    FillFloats(arr, N, a, b);
    PrintFloats(arr, N); printf("\n");
    printf("\n");

    WriteText(TEXT_FILE, arr, N);
    WriteBinary(BIN_FILE, arr, N);

    float* arrOne = NULL;
    int lenghtOne = 0;
    arrOne = ReadText(TEXT_FILE, &lenghtOne);
    PrintFloats(arrOne, lenghtOne); printf("\n");
    free(arrOne);

    float* arrTwo = NULL;
    int lenghtTwo = 0;
    arrTwo = ReadBinary(BIN_FILE, &lenghtTwo);
    PrintFloats(arrTwo, lenghtTwo); printf("\n");
    free(arrTwo);

    FileDump(TEXT_FILE); printf("\n");
    FileDump(BIN_FILE); printf("\n");

    printf("\n");

    FileDumpPlus(TEXT_FILE); printf("\n");
    FileDumpPlus(BIN_FILE); printf("\n");
    return 0;
}