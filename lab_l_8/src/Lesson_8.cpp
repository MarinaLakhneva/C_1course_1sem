#pragma warning(disable:4996) // Отключает предупреждения об устаревших функциях типа printf и scanf
#include <locale.h> // ипользуется для распознавания русского языка
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void Print(double const arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("arr_%d", i);
		printf(" = %lf", arr[i]);
		printf("\n");
	}
}

double Random(double a, double b) {
	double c = 0;
	int p = rand();
	c = a + (p * (b - a) / RAND_MAX);
	return c;
}


void PrintHistogram(int counters[], int numCounters) {
	for (int i = 0; i < numCounters; i++) {
		printf("\n");
		printf("numCounters = %d", (i+1));
		printf("\n");
		printf("count = %d", counters[i]);
	}
}

void DrawHistogram(int counters[], int numCounters, int width) {
int s = 183;
//printf("%s", &s);

double max = 0;
	for (int i = 0; i < numCounters; i++) {
		if (counters[i] > max) {
			max = counters[i];
		}
		else {

		}
	}

	double mult = width / max;
	printf("\n");
	printf("\n");
	for (int i = 0; i < numCounters; i++) {
		printf("%d ", (i + 1));
		if (counters[i] == 0) {
			for(int i = 0; i < width; i++)
			printf("%s", &s);
		}
		else {
			double n = (counters[i] * mult);
			for (double i = 0; i < n; i++){
				printf("o");
			}
			for (double i = n; i <= (width-1); i++) {
				printf("%s", &s);
			}
		}
		printf("\n");
	}
}

void BuildHistogram(double const arr[], int size, double left, double right, int counters[], int numCounters) {
// Первое решение (не совсем по заданию)	
	//int count = 0;
	//double a = left;
	//double b = right;

	//double h = ((b - a)/ numCounters);

	//for (int i = 1; i <= numCounters; i++) {
	//	b = 0;
	//	b = a + h;
	//	int num = i;
	//	for (int i = 0; i < size; i++) {
	//		if ((arr[i] > a) && (arr[i] < b)) {
	//			count++;
	//		}
	//		else {

	//		}
	//	}
	//	counters[i - 1] = count;
	//	count = 0;
	//	a = b;
	//	//printf("\n");
	//	//printf("numCounters = %1.0d", num);
	//	//printf("\n");
	//	//printf("count = %d", counters[i - 1]);
	//	num = 0;
	//}
	//PrintHistogram(counters, numCounters);

// Второе решение
		double a = left;
		double b = right;

		double h = ((b - a)/ numCounters);

		int* val_count; 
		val_count = (int*)malloc(size * sizeof(int));

		for (int i = 0; i < size; i++) {
			int str = (arr[i] - a) / h;
			val_count[i] = 1 + str; 
			str = 0;
			//printf("\n");
			//printf("val_count = %d", val_count[i]);
		}

		int count = 0;
		for (int i = 1; i <= numCounters; i++) {
			for (int j = 0; j < size; j++) {
				if (i == val_count[j]) {
					count++;
				}
				else {

				}
			}
			counters[i - 1] = count;
			count = 0;
		}
		printf("\n");
		PrintHistogram(counters, numCounters);
		int width = 16;
		DrawHistogram(counters, numCounters, width);
}

void FillRandom(double arr[], int size, double a, double b) {
	for (int i = 0; i < size; i++) {
		double c = Random(a, b);
		arr[i] = c;
	}
	Print(arr, size);
	
	printf("\n");
	int numCounters;
	printf("numCounters = ");
	scanf("%d", &numCounters);

	int* counters;
	counters = (int*)malloc(numCounters * sizeof(int));

	BuildHistogram(arr, size, a, b, counters, numCounters);
}

int main() {
	setlocale(LC_CTYPE, "Russian"); // ипользуется для распознавания русского языка (LC_ALL - не использовать)
	//int N = 10;
	//int p = RAND_MAX;
	//printf("%d ", p);
	//printf("\n");

	//for (int i = 0; i < N; i++) {
	//	int k = rand() % 20; //любое число в диапазоне[0, 20)
	//	printf("%d ", k);
	//}

	const int N = 10;
	double a = 0.2;
	double b = 0.6;


	double* arr;
	arr = (double*)malloc(N * sizeof(int));

	FillRandom(arr, N,  a,  b);
	return 0;
}