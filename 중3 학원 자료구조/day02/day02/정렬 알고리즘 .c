#include <stdio.h>

// ��������   : ���� �����Ϳ��� ū ������ ������ ����
// ��������   : ū �����Ϳ��� ���� ������ ������ ����

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
		// ����� : ���� ���� ���
		printArr(arr);
	}
	printArr(arr);



}