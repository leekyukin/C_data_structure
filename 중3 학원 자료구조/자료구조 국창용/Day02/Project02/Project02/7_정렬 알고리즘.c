#include<stdio.h>

// 정렬 : 데이터를 순서있게 정리한 형태
// ㄴ> 1. 오름차순(Ascending)	: 작은 데이터에서 큰 데이터 순으로 정렬
// ㄴ> 2. 내림차순(Descending)	: 큰 데이터에서 작은 데이터 순으로 정렬

// ex) 1 2 3 4 5 6	: 오름차순
// ex) 6 5 4 3 2 1  : 내림차순

void printArr(int arr[]) {
	printf("arr = ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[5] = { 4,8,2,7,6 };
	int tmp;

	printArr(arr);

	// 정렬 후 출력
	for (int i = 0; i < 4; i++) {				// 앞의 배열 index
		for (int j = i + 1; j < 5; j++) {		// 다음 배열 index
			if (arr[i] > arr[j]) {	// 앞의 요소가 크면
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}

		// 디버그 : 정렬 과정 출력
		// printArr(arr);
	}

	printArr(arr);
}