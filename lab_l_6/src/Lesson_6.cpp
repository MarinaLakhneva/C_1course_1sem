#pragma warning(disable:4996) // Отключает предупреждения об устаревших функциях типа printf и scanf
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <locale.h> // ипользуется для распознавания русского языка

void Print(int arr[], int size) {
	printf("\n");
	for (int i = 0; i < size; i++) {
		//printf("arr_%d", i);
		//printf(" = %d ", arr[i]);
		//printf("\n");
		printf(" %d ", arr[i]);
	}
	printf("\n");
}

void Reverse(int arr[], int left, int right, int size) { 
	int k = right - 1; 
	int p = 0; 
	for (int i = left; i < right; i++) {
		if ((k == i) || (i == k+1)) {
			break;
		}
		p = arr[i];
		arr[i] = arr[k];
		arr[k] = p;
		k--;
		p = 0;
	}
	Print(arr, size);
}

void Shift1(int arr[], int size) {
	int copy = 0;
	int shift_var = 1;

	for (int i = 0; i < shift_var; i++) {
		copy = arr[i];
		for (int i = 0; i < (size-1); i++) {
			arr[i] = arr[i + 1];
		}
		arr[size - 1] = copy;
	}
	//Print(arr, size);
}

void Shift_Ver1(int arr[], int size, int delta) {
	if ((delta == 0) || (delta >= size)) {

	}
	else {
		for (int i = 0; i < delta; i++) {
			Shift1(arr, size);
		}
	}
	Print(arr, size); // сдвигаем на delta позиций
}

void Shift_Ver2(int arr[], int size, int delta) {
	Shift_Ver1(arr, size, delta);
	Reverse(arr, 0, size, size); // переворачиваем весь массив
	Reverse(arr, delta, size, size); // переворачиваем левую часть
	Reverse(arr, 0, delta, size); // переворачиваем правую часть
}

void Fill(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = i + 1;
	}
	Print(arr, size);

	int delta;
	printf("Введите величину сдвига - delta = ");
	scanf("%d", &delta);
	//Shift1(arr, size);
	//Shift_Ver1(arr, size, delta);
	Shift_Ver2(arr, size, delta);
}

int main() {
	setlocale(LC_CTYPE, "Russian"); // ипользуется для распознавания русского языка (LC_ALL - не использовать)

	int N = 9;
	int* arr;
	arr = (int*)malloc(N * sizeof(int));

	Fill(arr, N);
	return 0;
}