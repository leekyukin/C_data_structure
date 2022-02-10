#include<stdio.h>

int main() {
	int num;

	printf("1.정수 입력 : ");
	scanf_s("%d", &num);

	for (int i = 1; i <= num; i++) {
		printf("%d ", i * num);
	}
	printf("\n\n");


	printf("2.정수 입력 : ");
	scanf_s("%d", &num);

	for (int i = num; i >= 1; i--) {
		printf("%d ", i);
	}
	printf("\n");

}