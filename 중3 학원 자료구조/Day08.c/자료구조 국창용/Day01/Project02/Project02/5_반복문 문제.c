#include<stdio.h>

int main() {
	int num;

	printf("1.���� �Է� : ");
	scanf_s("%d", &num);

	for (int i = 1; i <= num; i++) {
		printf("%d ", i * num);
	}
	printf("\n\n");


	printf("2.���� �Է� : ");
	scanf_s("%d", &num);

	for (int i = num; i >= 1; i--) {
		printf("%d ", i);
	}
	printf("\n");

}