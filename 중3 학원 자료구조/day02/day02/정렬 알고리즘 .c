#include <stdio.h>

// 오름차순   : 작은 데이터에서 큰 데이터 순으로 정렬
// 내림차순   : 큰 데이터에서 작은 데이터 순으로 정렬

void printArr(int arr[]) {
	printf("arr = ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[5] = { 4,8,2,7,6 };

	printArr(arr);

	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (arr[i] > arr[j]) {
				int tmp = 0;
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
		// 디버그 : 정렬 과정 출력
		printArr(arr);
	}
	printArr(arr);



}