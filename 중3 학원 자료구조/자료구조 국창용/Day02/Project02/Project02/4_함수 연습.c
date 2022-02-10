#include<stdio.h>


int total(int n) {
	int sum = 0;

	for (int i = 1; i <= n; i++) {
		sum += i;
	}

	return sum;
}

void star(n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("*");
		}
		printf("\n");
	}
}

int prime(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}


int main() {
	
	int n;

	printf("1.정수 입력 : ");
	scanf_s("%d", &n);

	printf("1 ~ %d까지의 합 : %d\n\n", n, total(n));


	printf("2.정수 입력 : ");
	scanf_s("%d", &n);

	star(n);	// 전달한 만큼 n x n 별찍기를 출력하는 함수

	
	printf("\n3.정수 입력 : ");
	scanf_s("%d", &n);

	// prime(n)  : 소수면 1을 반환
	//		       아니면 0을 반환

	if (prime(n)) {
		printf("소수 입니다\n");
	}

	else {
		printf("소수가 아닙니다\n");
	}


}