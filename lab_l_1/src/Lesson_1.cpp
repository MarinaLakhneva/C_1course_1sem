#pragma warning(disable:4996) // Отключает предупреждения об устаревших функциях типа printf и scanf
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <locale.h> // ипользуется для распознавания русского языка

int main(void) {
	setlocale(LC_CTYPE, "Russian"); // ипользуется для распознавания русского языка (LC_ALL - не использовать)
	double x;

	printf("Введите x:\n"); // \n - перевод строки 
	scanf("%lf", &x);
	
	printf("Синус %lf равен %lf\n", x, sin(x)); //  спецификаторы "%i %lf" для ввода int, double
	return 0;
}
