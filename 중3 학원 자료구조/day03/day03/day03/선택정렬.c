#include<stdio.h>

void printarr(int arr[]) {
	for (int i = 0; i < 5; i++) {
		printf("%d", arr[i]);
	}
	printf("\n");
}



int main() {
	int arr[5] = { 4,8,2,7,6 };

	printf("���� �� : ");
	printarr(arr);


	// ��������
	/*for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (arr[i] > arr[j]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}

		printf("���� ���� : ");
		printarr(arr);
	}*/

	//// �������� : 2���� ��ġ���� �ڽ� ������ ���ϸ� ��ġ�� ���� ���ĵǴ� ���

	/*for (int i = 1; i < 5; i++) {
		for (int j = 0;  j < i; j++) {
			if (arr[j] > arr[i]) {
				int tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
		printf("���� �� : ");
		printarr(arr);
	}*/

	//// ���� ���� :  ������ �� �����͸� ���ϸ鼭 ������ ������ ���ư��� ���� ���

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
	//		printf("���� ���� : ");
	//		printarr(arr);

	//		if (count == 0) break;
	//	}


	printf("���� �� : ");
	printarr(arr);
	

	return 0;
}