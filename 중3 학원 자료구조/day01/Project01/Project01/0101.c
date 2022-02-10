#include <stdio.h>

int main(void) {
	// 공백별존나게 만들기
	int num1; printf("별 줄수 입력 : "); scanf_s("%d",&num1);
	int count = 1;
	for (int i = 0; i < num1; i++){
		//공백찍기 반복
		for (int k = 0; k < num1 - 1; k++) {
			printf(" ");
		}
		// 별찍기 반복
		for (int j = 0; j < num1; j++) {
			
			printf("*");

		}
		printf("\n");
		
	}
	// 거꾸로수 출력 
	int num;
	printf("정수 입력 : ");
	scanf_s("%d", &num);
	while (num != 0) {
		printf("출력 : %d\n", num % 10);
		printf("저장될 값 : %d\n", num /10);
		num /= 10;
	}
	printf("\n");

	





	return 0;
}