#include<stdio.h>

void printarr(int arr[]) {
	for (int i = 0; i < 5; i++) {
		printf("%d", arr[i]);
	}
	printf("\n");
}



int main() {
	int arr[5] = { 4,8,2,7,6 };

	printf("정렬 전 : ");
	printarr(arr);


	// 선택정렬
	/*for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (arr[i] > arr[j]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}

		printf("정렬 과정 : ");
		printarr(arr);
	}*/

	//// 삽입정렬 : 2번쨰 위치부터 자신 전까지 비교하며 위치에 들어가서 정렬되는 방식

	/*for (int i = 1; i < 5; i++) {
		for (int j = 0;  j < i; j++) {
			if (arr[j] > arr[i]) {
				int tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
		printf("정렬 중 : ");
		printarr(arr);
	}*/

	//// 버블 정렬 :  인접한 두 데이터를 비교하면서 데이터 끝까지 나아가는 정렬 방식

	//while (1) {
	//	int count = 0;

	//		for (int i = 0; i < 4; i++) {
	//			if (arr[i] > arr[i + 1]) {
	//				int tmp = arr[i];
	//				arr[i] = arr[i+1];
	//				arr[i+1] = tmp;

	//				count++;
	//			}
	//		}
	//		printf("정렬 과정 : ");
	//		printarr(arr);

	//		if (count == 0) break;
	//	}


	printf("정렬 후 : ");
	printarr(arr);
	

	return 0;
}