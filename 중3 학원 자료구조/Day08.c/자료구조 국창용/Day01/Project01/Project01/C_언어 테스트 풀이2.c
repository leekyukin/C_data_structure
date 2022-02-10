#include<stdio.h>

int main() {
	// 2번 문제
	int n1, n2;

	printf("두 정수 입력 : ");
	scanf("%d %d", &n1, &n2);

	if (n1 > n2) {
		printf("큰 수는 n1(%d)\n", n1);
	}

	else if (n1 == n2) {
		printf("두 수는 %d %d 로 같다\n", n1, n2);
	}

	else {
		printf("큰 수는 n2(%d)\n", n2);
	}

	printf("\n");


	// 3번 문제
	int num;

	printf("정수 입력 : ");
	scanf("%d", &num);

	printf("거꾸로 수 : ");

	while (num != 0) {
		printf("%d", num % 10);
		num /= 10;
	}

	printf("\n\n");


	// 4번 문제
	int star;

	printf("찍을 별의 줄수 : ");
	scanf("%d", &star);
	
	for (int i = 0; i < star; i++) {
		// 공백 찍기 반복
		for (int j = 0; j < star - 1 - i; j++) {
			printf(" ");
		}

		// 별 찍기 반복
		for (int j = 0; j <= i; j++) {
			printf("*");
		}

		printf("\n");
	}

}