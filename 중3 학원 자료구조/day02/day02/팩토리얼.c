#include <stdio.h>

int main() {
	// Factorial = ������
	int num;
	int fac = 1;

	printf("���� �Է� : ");
	scanf_s("%d", &num);

	for (int i = num; i >= 1; i--) {
		fac *= i; // fax = fac * i;
	
		printf("%d  x ", i);
	}

	printf("��� : %d\n", fac);

	return 0;
}