#include <stdio.h>
#define MAX 5  // ��ũ�� ���  : ������� �̸��� �ٿ�������
			   // ġȯ �����̶�� �Ѵ�
int main() {
	
	int arr[MAX]; 
	int count = 10;

	for (int i = 0; i < MAX; i++) {
		arr[i] = count;
		count += 10;
	}

	printf("arr = ");

	for (int i = 0; i < MAX; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
}