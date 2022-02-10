#include<stdio.h>

void printArr(int* arr) {	// int arr[]

	for (int i = 0; i < 5; i++) {
	//	printf("%d ", arr[i]);
		printf("%d ", *(arr + i));
	}
	printf("\n");
}

void selectSort(int* arr) {
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (*(arr + i) > *(arr + j)) {
				int tmp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = tmp;
			}
		}
	}
}

void insertSort(int* arr) {
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < i; j++) {
			if (*(arr + j) > * (arr + i)) {
				int tmp = *(arr + j);
				*(arr + j) = *(arr + i);
				*(arr + i) = tmp;
			}
		}
	}
}

void bubbleSort(int* arr) {
	while (1) {
		int count = 0;

		for (int i = 0; i < 4; i++) {
			if (*(arr + i) > * (arr + i + 1)) {
				int tmp = *(arr + i);
				*(arr + i) = *(arr + i + 1);
				*(arr + i + 1) = tmp;

				count++;
			}
		}

		if (count == 0) break;
	}
}

int main() {
	int arr[5] = { 4,8,2,7,6 };

	printArr(arr);

	//selectSort(arr);	// 선택 정렬
	//insertSort(arr);	// 삽입 정렬
	bubbleSort(arr);	// 버블 정렬

	printArr(arr);
}