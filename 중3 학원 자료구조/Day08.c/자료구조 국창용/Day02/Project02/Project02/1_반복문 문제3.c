#include<stdio.h>

int main() {
	int num;
	int count = 0;

	printf("1.정수 입력 : ");
	scanf_s("%d", &num);

	for (int i = 1; i <= num; i++) {
		if (num % i == 0) {
			printf("%d ", i);
			count++;
		}
	}
	printf("(%d개)\n\n", count);


	printf("2.정수 입력 : ");
	scanf_s("%d", &num);
	count = 0;

	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			printf("약수존재 => 소수아님\n");
			count++;
			break;
		}
	}

	if (count == 0) {
		printf("약수없음 => 소수\n");
	}

}