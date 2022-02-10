#include<stdio.h>

int main() {
	// 1. 기본 별찍기 : N x N 행렬
	int star;

	printf("찍을 별의 줄수 : ");
	scanf_s("%d", &star);

	for (int i = 0; i < star; i++) {		// 행 반복(= 줄 반복)
		for (int j = 0; j < star; j++) {	// 열 반복(= 데이터 반복)
			printf("*");
		}

		printf("\n");
	}

	printf("\n");


	// 2. ㅁ 별찍기
	for (int i = 0; i < star; i++) {		// 행 반복(= 줄 반복)
		for (int j = 0; j < star; j++) {	// 열 반복(= 데이터 반복)
			if (i == 0 || j == 0 || i == star - 1 || j == star - 1)
				printf("*");

			else
				printf(" ");
		}

		printf("\n");
	}

	printf("\n");


	// 3. + 별찍기
	for (int i = 0; i < star; i++) {		// 행 반복(= 줄 반복)
		for (int j = 0; j < star; j++) {	// 열 반복(= 데이터 반복)
			if (i == star / 2 || j == star / 2)
				printf("*");

			else
				printf(" ");
		}

		printf("\n");
	}

	printf("\n");


	// 4. x 별찍기
	for (int i = 0; i < star; i++) {		// 행 반복(= 줄 반복)
		for (int j = 0; j < star; j++) {	// 열 반복(= 데이터 반복)
			if (i == j || i + j == star - 1)
				printf("*");

			else
				printf(" ");
		}

		printf("\n");
	}

	printf("\n");


	// 5. 직각 삼각형
	for (int i = 0; i < star; i++) {
		for (int j = 0; j <= i; j++) {
			printf("*");
		}

		printf("\n");
	}

	printf("\n");

	// 6. 직각 삼각형 (좌우 반전)
	for (int i = 0; i < star; i++) {
		for (int j = 0; j < star - 1 - i; j++) {
			printf(" ");
		}

		for (int j = 0; j <= i; j++) {
			printf("*");
		}

		printf("\n");
	}

	printf("\n");


	// 7. 피라미드
	for (int i = 0; i < star; i++) {
		for (int j = 0; j < star - 1 - i; j++) {
			printf(" ");
		}

		for (int j = 0; j <= i * 2; j++) {
			printf("*");
		}

		printf("\n");
	}

	printf("\n");

}