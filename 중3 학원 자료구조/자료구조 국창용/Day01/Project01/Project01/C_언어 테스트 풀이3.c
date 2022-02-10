#include<stdio.h>

void printArr(int arr[]) {
	printf("arr = { ");
	for (int i = 0; i < 10; i++) {
		printf("%d, ", arr[i]);
	}
	printf("\b\b }\n");
}

int main() {
	// 5번 문제
	int arr[10];
	int count = 10;

	for (int i = 0; i < 10; i++) {
		arr[i] = count;
		count--;
	}


	// 6번 문제
	//printf("arr = { ");
	//for (int i = 0; i < 10; i++) {
	//	printf("%d, ", arr[i]);
	//}
	//printf("\b\b }\n");

	// 7번 문제
	printArr(arr);

	for (int i = 0; i < 10; i++) {
		printArr(arr);	// 함수의 재사용
	}

}