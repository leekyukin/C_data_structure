#include <stdio.h>

int main(void) {
	// ���麰������ �����
	int num1; printf("�� �ټ� �Է� : "); scanf_s("%d",&num1);
	int count = 1;
	for (int i = 0; i < num1; i++){
		//������� �ݺ�
		for (int k = 0; k < num1 - 1; k++) {
			printf(" ");
		}
		// ����� �ݺ�
		for (int j = 0; j < num1; j++) {
			
			printf("*");

		}
		printf("\n");
		
	}
	// �Ųٷμ� ��� 
	int num;
	printf("���� �Է� : ");
	scanf_s("%d", &num);
	while (num != 0) {
		printf("��� : %d\n", num % 10);
		printf("����� �� : %d\n", num /10);
		num /= 10;
	}
	printf("\n");

	





	return 0;
}