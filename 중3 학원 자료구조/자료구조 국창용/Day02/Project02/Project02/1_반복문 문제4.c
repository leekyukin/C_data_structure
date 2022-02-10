#include<stdio.h>

int main() {
	// Factorial = 누적곱
	int num;
	int fac = 1;

	printf("정수 입력 : ");
	scanf_s("%d", &num);

	for (int i = num; i >= 1; i--) {
		fac *= i;	// fac = fac * i;

		printf("%d x ", i);
	}

	printf("\b\b= %d\n", fac);

}