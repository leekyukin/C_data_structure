#include<stdio.h>

int main() {
	// Factorial = ������
	int num;
	int fac = 1;

	printf("���� �Է� : ");
	scanf_s("%d", &num);

	for (int i = num; i >= 1; i--) {
		fac *= i;	// fac = fac * i;

		printf("%d x ", i);
	}

	printf("\b\b= %d\n", fac);

}