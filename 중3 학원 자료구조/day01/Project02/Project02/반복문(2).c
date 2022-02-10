#include <stdio.h>

int main(void) {
	// 불특정 횟수 반복
	// 1. 조건식을 이용한 반복
	int num = 1;
	
	while (num != 0) {
		printf("정수 입력(0 입력시 종료) : ");
		scanf_s("%d", &num);

		printf("num = %d\n\n", num);
	}
	printf("\n");

	//2.무한반복을 이용한 반복
	while (1) {
		printf("정수 입력(0 입력시 종료) : ");
		scanf_s("%d", &num);

		if (num == 0)
			break; //제어문을 탈출하는 보조 제어문
	}
	return 0;
}