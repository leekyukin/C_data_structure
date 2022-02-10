#include <stdio.h>


int total(int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += i;
	}
	return sum;
}

void star(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("*");
		}
		printf("\n");
	}
}

	int prime(int n) {
		for (int i = 2; i < n; i++) {
			if (n% i == 0) {
				return 0;
			}
		}
		return 1;
	}


int main() {

	int n;

	printf("1. 정수 입력 : ");
	scanf_s("%d", &n);

	printf(" 1 ~ %d까지의 합 : %d\n\n", n, total(n));

	

	printf("2. 정수 입력 : ");
	scanf_s("%d", &n);

	star(n); 

	printf("3. 정수 입력 : ");
	scanf_s("%d", &n);

	if (prime(n))


	return 0;
}