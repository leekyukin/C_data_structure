#include<stdio.h>

int main() {
	int money = 1;		// ���ݾ�
	int total = 0;		// ����(= ����)��


	for (int day = 1; day <= 30; day++) {
		total += money;		// total = total + money;

		printf("%d ����) ���ݾ� : %d��, ������ : %d��\n", day, money, total);

		money *= 2;

	}

	printf("�ѱݾ� : %d��\n", total);

}