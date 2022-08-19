#pragma warning(disable:4996) // Отключает предупреждения об устаревших функциях типа printf и scanf
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h> // ипользуется для распознавания русского языка

void PrintTable(double x, double f, int i, int m) { // требование: передать в функцию a, b, m, НО я не поняла как тогда сделать вывод всего((( и поэтому передаю i, x, m и значение фун. f
	printf("+---+---+-------+-------+-----------+");
	printf("\n");
	if (i == 0) {
		printf("| i | x |   f   |   g   | f(x)-g(x) |");
		printf("\n");
		printf("+---+---+-------+-------+-----------+");
		printf("\n");
	}

	printf("| %-2.1d|", i);						
													
	printf("%2.1f|", x);

	printf("%7.1le|", f);

	double g = sin(x) * sin(x);
	printf("%7.1le| ", g);

	printf("%-10.3le|", (f - g));
	printf("\n");
	if (i == (m-1)) {
		printf("+---+---+-------+-------+-----------+");
	}
}
// %8.2lf - 8-ширина; 2-точность, т.е. выделяем 8 символов и хотим видеть 2 знака после запятой
// если с "-": т.е. %-8.2lf - минус говорит о том, что необходимо выровнять число по левому краю используемой области

int main() {
	setlocale(LC_CTYPE, "Russian"); // ипользуется для распознавания русского языка (LC_ALL - не использовать)
	//int N = 4;

	//double x = 0.5;
	//double a = 0.53;
	//double b = 0.85;
	//double m = 4;

	double a;
	printf("a = "); 
	scanf("%lf", &a);

	double b;
	printf("b = ");
	scanf("%lf", &b);

	double m;
	printf("m = ");
	scanf("%lf", &m);

	while ((a >= 1) || (b >= 1) || (m < 1)) {
		if (a >= 1) {
			printf("Некорректная величина \n");
			printf("a = ");
			scanf("%lf", &a);
		}
		else if (b >= 1) {
			printf("Некорректная величина \n");
			printf("b = ");
			scanf("%lf", &b, "\n");
		}
		else if (m < 1) {
			printf("Некорректная величина \n");
			printf("m = ");
			scanf("%lf", &m, "\n");
		}
	}

	//double u_prev = 0.25;
	double u_next = 0;

	//for (int k = 1; k < N; k++) {
	for (int i = 1; i < (m + 1); i++) {
		double h = (b - a) / (m - 1);
		double x = a + h * (i - 1);

		double u_prev = x*x;  

		int k = 1;
		double sum = 10000;
		double s = 0;
		while (sum != s) {
			sum = 0;
			s += u_prev;

			//printf("u = %le  ", u_prev);
			//printf("s = %le", s);
			//printf("\n");
			double d = (-2.0) / (2 * k * k + 3 * k + 1);
			k++;
			double v_k = d * x * x;

			u_next = u_prev * v_k;
			u_prev = u_next;
			sum = s + u_prev;
		}
		PrintTable(x, s, (i - 1), m);
	}
	//}
	//printf("x = %f", x);
	//printf("\n");

	//double f = sum;
	//printf("f = %le", f);
	//printf("\n");

	//double g = sin(x) * sin(x);
	//printf("g = %le", g);
	//printf("\n");

	//printf("f - g = %le", (f - g));
	//printf("\n");
	return 0;
}