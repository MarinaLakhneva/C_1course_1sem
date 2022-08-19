#pragma warning(disable:4996) // Отключает предупреждения об устаревших функциях типа printf и scanf
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <locale.h> // ипользуется для распознавания русского языка

int main() {
	setlocale(LC_CTYPE, "Russian"); // ипользуется для распознавания русского языка (LC_ALL - не использовать)
	const double pi = 3.14;
	double d = 0;

	double m;
	printf("Введите массу:\n"); // \n - перевод строки 
	scanf("%lf", &m);
	//if (m > 100) {
	//	printf("Масса недопустима (m < 100)\n Введите повторно\n");
	//	printf("m = "); 
	//	scanf("%lf", &m);
	//}

	double l;
	printf("Введите длину:\n");  
	scanf("%lf", &l);
	//if (l > 10) {
	//	printf("Длина недопустима (l < 10)\n Введите повторно\n");
	//	printf("l = ");
	//	scanf("%lf", &l);
	//}

	double p;
	printf("Введите плотность:\n"); 
	scanf("%lf", &p);
	//if (p > 500) {
	//	printf("Плотность недопустима (p < 500)\n Введите повторно\n");
	//	printf("p = ");
	//	scanf("%lf", &p);
	//}

	while ((m > 100) || (l > 10) || (p > 500)) {
		if (m > 100) {
			printf("Масса недопустима\n");
			printf("m = ");
			scanf("%lf", &m);
		}
		else if (l > 10) {
			printf("Длина недопустима\n");
			printf("l = ");
			scanf("%lf", &l, "\n");
		}
		else if (p > 500) {
			printf("Плотность недопустима\n");
			printf("p = ");
			scanf("%lf", &p, "\n");
		}
	}
	d = 2 * sqrt(m / (pi * p * l));
	printf("d = %lf", d);
	return 0;
}
