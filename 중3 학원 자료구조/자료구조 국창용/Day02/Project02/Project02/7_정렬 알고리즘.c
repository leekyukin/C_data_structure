#include<stdio.h>

// ���� : �����͸� �����ְ� ������ ����
// ��> 1. ��������(Ascending)	: ���� �����Ϳ��� ū ������ ������ ����
// ��> 2. ��������(Descending)	: ū �����Ϳ��� ���� ������ ������ ����

// ex) 1 2 3 4 5 6	: ��������
// ex) 6 5 4 3 2 1  : ��������

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

	// ���� �� ���
	for (int i = 0; i < 4; i++) {				// ���� �迭 index
		for (int j = i + 1; j < 5; j++) {		// ���� �迭 index
			if (arr[i] > arr[j]) {	// ���� ��Ұ� ũ��
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}

		// ����� : ���� ���� ���
		// printArr(arr);
	}

	printArr(arr);
}