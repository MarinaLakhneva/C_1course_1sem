#pragma warning(disable:4996) // Отключает предупреждения об устаревших функциях типа printf и scanf
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <locale.h> // ипользуется для распознавания русского языка
#define LENGTH 10 // фиксируйте максимальное количество цифр в числе

void print_(int length) {
	for (int i = 0; i < LENGTH; i++) {
		if (i < (LENGTH -length)) {
			printf(" ");
		}
		else {
			printf("-");
		}
	}
}

void Print(int const digits[], int length) {
	for (int i = (length-1); i >= 0; i--) {
		printf("%d", digits[i]);
	}
	printf("\n");
}

int Fill(int number, int digits[], int length) { 
	int count = 0;
	int number_ = number;
	while (number_ != 0) { // находим количество цыфр в числе
		number_ = number_ / 10;
	count++;
	}

	if (count > length) {
		printf("Возникло переполнение массива!");
	}

	for (int i = 0; i < length; i++) {
		digits[i] = number % 10;      //берем последнюю цыфру с числа
		number = number / 10;         //забираем эту цыфру с числа
	}
	Print(digits, length);
	return count;
}

int Collect(int const digits[], int length) {
	int c = 0;
	for (int i = 0; i < length; i++) {
		c += pow(10, i) * digits[i];
	}
	return(c);
}

int Add(int const A[], int const B[], int C[], int length) { 
	int overflow = 0;
	int k = 0;

	int val = 0;
	for (int i = 0; i < length; i++) {
		if ((A[i] == 0) && (B[i] == 0)) {
			if (overflow != 0) {
				C[i] = overflow;
				val = i;
			}
		}
		C[i] = A[i] + B[i] + overflow;
		overflow = 0;
		if (C[i] >= 10) {
			k = C[i];
			C[i] = C[i] % 10;
			overflow = k / 10;
		}
	}
	return val;
}

int main() {
	setlocale(LC_CTYPE, "Russian"); // ипользуется для распознавания русского языка (LC_ALL - не использовать)

	int a, b, c;

	printf("Введите a = ");
	scanf("%d", &a);
	printf("\n");
	printf("Введите b = ");
	scanf("%d", &b);
	printf("\n");
	printf("a + b = %d", (a + b));
	printf("\n");

	int *A;
	int *B;
	int *C;

	//Изначально делала так
	//int count = 0;
	//int a_ = a;
	//while (a_ != 0) { // находим количество цыфр в числе
	//	a_ = a_ / 10;
	//	count++;
	//}

	//int counter = 0;
	//int b_ = b;
	//while (b_ != 0) {
	//	b_ = b_ / 10;
	//	counter++;
	//}

	//int size = 0;
	//if (count > counter) {
	//	size = count;
	//}
	//else {
	//	size = counter;
	//}

	A  = (int*)malloc(LENGTH * sizeof(int));
	B = (int*)malloc(LENGTH * sizeof(int));

	printf("\n");
	int count = Fill(a, A, LENGTH);
	int counter = Fill(b, B, LENGTH);

	C = (int*)malloc(LENGTH * sizeof(int));

	int val = Add(A, B, C, LENGTH);

	print_(val);
	printf("\n");

	Print(C, LENGTH);
	printf("\n");

	int c_ = Collect(C, LENGTH);
	printf("c = %d", c_);
	return 0;
}