#include<stdio.h>

int main() {
	int n1, n2, n3;
	int max, min;

	printf("�� ���� �Է� : ");
	scanf_s("%d %d %d", &n1, &n2, &n3);

	max = n1;
	min = n1;

	// �ִ밪
	if (max < n2) {
		max = n2;
	}

	if (max < n3) {
		max = n3;
	}

	// �ּҰ�
	if (min > n2) {
		min = n2;
	}

	if (min > n3) {
		min = n3;
	}

	printf("�ִ밪 : %d\n", max);
	printf("�ּҰ� : %d\n", min);
	
}