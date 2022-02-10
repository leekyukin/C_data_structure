#include <stdio.h>

int main() {
	int arr[10];

	for (int i = 0; i < 10; i++) {
		printf("%d번째 정수 입력 :", i + 1);
		scanf_s("%d", &arr[i]);
	}
	int max=0;  int min=0;
	for (int i = 1; i < 11; i++) {
		 
		max = arr[0]; min= arr[0];
		
		if (max < arr[i]) {
			max = arr[i]; 
		}
		
	}
	for (int i = 1; i < 11; i++) {
		 if (min > arr[i]) {
			min = arr[i];
		}
	}
	printf("최대값 : %d\n", max);
	printf("최소값 : %d", min);
	
	
	return 0;
}