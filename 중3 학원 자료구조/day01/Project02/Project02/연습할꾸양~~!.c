#include <stdio.h>

int main() {
	int arr[10];

	for (int i = 0; i < 10; i++) {
		printf("%d��° ���� �Է� :", i + 1);
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
	printf("�ִ밪 : %d\n", max);
	printf("�ּҰ� : %d", min);
	
	
	return 0;
}