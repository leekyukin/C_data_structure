#include <stdio.h>

int main(void) {
	// ��Ư�� Ƚ�� �ݺ�
	// 1. ���ǽ��� �̿��� �ݺ�
	int num = 1;
	
	while (num != 0) {
		printf("���� �Է�(0 �Է½� ����) : ");
		scanf_s("%d", &num);

		printf("num = %d\n\n", num);
	}
	printf("\n");

	//2.���ѹݺ��� �̿��� �ݺ�
	while (1) {
		printf("���� �Է�(0 �Է½� ����) : ");
		scanf_s("%d", &num);

		if (num == 0)
			break; //����� Ż���ϴ� ���� ���
	}
	return 0;
}