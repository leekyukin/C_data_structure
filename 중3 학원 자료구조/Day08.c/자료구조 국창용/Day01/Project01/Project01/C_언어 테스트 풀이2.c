#include<stdio.h>

int main() {
	// 2�� ����
	int n1, n2;

	printf("�� ���� �Է� : ");
	scanf("%d %d", &n1, &n2);

	if (n1 > n2) {
		printf("ū ���� n1(%d)\n", n1);
	}

	else if (n1 == n2) {
		printf("�� ���� %d %d �� ����\n", n1, n2);
	}

	else {
		printf("ū ���� n2(%d)\n", n2);
	}

	printf("\n");


	// 3�� ����
	int num;

	printf("���� �Է� : ");
	scanf("%d", &num);

	printf("�Ųٷ� �� : ");

	while (num != 0) {
		printf("%d", num % 10);
		num /= 10;
	}

	printf("\n\n");


	// 4�� ����
	int star;

	printf("���� ���� �ټ� : ");
	scanf("%d", &star);
	
	for (int i = 0; i < star; i++) {
		// ���� ��� �ݺ�
		for (int j = 0; j < star - 1 - i; j++) {
			printf(" ");
		}

		// �� ��� �ݺ�
		for (int j = 0; j <= i; j++) {
			printf("*");
		}

		printf("\n");
	}

}