#include<stdio.h>

void printArr(int arr[]) {
	printf("arr = { ");
	for (int i = 0; i < 10; i++) {
		printf("%d, ", arr[i]);
	}
	printf("\b\b }\n");
}

int main() {
	// 5�� ����
	int arr[10];
	int count = 10;

	for (int i = 0; i < 10; i++) {
		arr[i] = count;
		count--;
	}


	// 6�� ����
	//printf("arr = { ");
	//for (int i = 0; i < 10; i++) {
	//	printf("%d, ", arr[i]);
	//}
	//printf("\b\b }\n");

	// 7�� ����
	printArr(arr);

	for (int i = 0; i < 10; i++) {
		printArr(arr);	// �Լ��� ����
	}

}