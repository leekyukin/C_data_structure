#include<stdio.h>

int main() {
	// 1. �⺻ ����� : N x N ���
	int star;

	printf("���� ���� �ټ� : ");
	scanf_s("%d", &star);

	for (int i = 0; i < star; i++) {		// �� �ݺ�(= �� �ݺ�)
		for (int j = 0; j < star; j++) {	// �� �ݺ�(= ������ �ݺ�)
			printf("*");
		}

		printf("\n");
	}

	printf("\n");


	// 2. �� �����
	for (int i = 0; i < star; i++) {		// �� �ݺ�(= �� �ݺ�)
		for (int j = 0; j < star; j++) {	// �� �ݺ�(= ������ �ݺ�)
			if (i == 0 || j == 0 || i == star - 1 || j == star - 1)
				printf("*");

			else
				printf(" ");
		}

		printf("\n");
	}

	printf("\n");


	// 3. + �����
	for (int i = 0; i < star; i++) {		// �� �ݺ�(= �� �ݺ�)
		for (int j = 0; j < star; j++) {	// �� �ݺ�(= ������ �ݺ�)
			if (i == star / 2 || j == star / 2)
				printf("*");

			else
				printf(" ");
		}

		printf("\n");
	}

	printf("\n");


	// 4. x �����
	for (int i = 0; i < star; i++) {		// �� �ݺ�(= �� �ݺ�)
		for (int j = 0; j < star; j++) {	// �� �ݺ�(= ������ �ݺ�)
			if (i == j || i + j == star - 1)
				printf("*");

			else
				printf(" ");
		}

		printf("\n");
	}

	printf("\n");


	// 5. ���� �ﰢ��
	for (int i = 0; i < star; i++) {
		for (int j = 0; j <= i; j++) {
			printf("*");
		}

		printf("\n");
	}

	printf("\n");

	// 6. ���� �ﰢ�� (�¿� ����)
	for (int i = 0; i < star; i++) {
		for (int j = 0; j < star - 1 - i; j++) {
			printf(" ");
		}

		for (int j = 0; j <= i; j++) {
			printf("*");
		}

		printf("\n");
	}

	printf("\n");


	// 7. �Ƕ�̵�
	for (int i = 0; i < star; i++) {
		for (int j = 0; j < star - 1 - i; j++) {
			printf(" ");
		}

		for (int j = 0; j <= i * 2; j++) {
			printf("*");
		}

		printf("\n");
	}

	printf("\n");

}