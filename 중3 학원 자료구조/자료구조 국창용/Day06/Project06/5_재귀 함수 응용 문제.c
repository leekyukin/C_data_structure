#include<stdio.h>

// �ϳ��� Ÿ��

void HanoiTowerMove(int n, char src, char sub, char des) {
	if (n == 1) {
		printf("����%d : %c ==> %c\n", n, src, des);
		return;
	}

	HanoiTowerMove(n - 1, src, des, sub);		// 1�� ��� : ���� ��հ� ������ ����� ����
	printf("����%d : %c ==> %c\n", n, src, des);
	HanoiTowerMove(n - 1, sub, src, des);		// 2�� ��� : ���� ��հ� ��� ����� ����
}

int main() {

	HanoiTowerMove(10, 'A', 'B', 'C');
			// (���ݰ���, ��߱��, �������, ���������)
}