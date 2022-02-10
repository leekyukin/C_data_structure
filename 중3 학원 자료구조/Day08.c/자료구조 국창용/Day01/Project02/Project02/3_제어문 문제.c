#include<stdio.h>

int main() {
	int n1, n2, n3;
	int max, min;

	printf("세 정수 입력 : ");
	scanf_s("%d %d %d", &n1, &n2, &n3);

	max = n1;
	min = n1;

	// 최대값
	if (max < n2) {
		max = n2;
	}

	if (max < n3) {
		max = n3;
	}

	// 최소값
	if (min > n2) {
		min = n2;
	}

	if (min > n3) {
		min = n3;
	}

	printf("최대값 : %d\n", max);
	printf("최소값 : %d\n", min);
	
}