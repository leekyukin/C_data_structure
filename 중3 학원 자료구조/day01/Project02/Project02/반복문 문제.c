#include <stdio.h>

int main(void) {
	int num; printf("정수 입력 : ");
	scanf("%d", &num);
	for (int i = 1; i < num+1; i++) {
		printf("%d\n", num * i);
	}

	for (int i = 0; i < num; i++) {
		printf("%d \n", num - i);
	}

	int n1; printf("세자리 정수 입력 : "); scanf("%d", &n1);
	printf("%d", n1 % 10);


	return 0;
}