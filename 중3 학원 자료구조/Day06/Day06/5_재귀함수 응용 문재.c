#include<stdio.h>

void HanoiTowerMove(int n, char src, char sub, char des) {

	if (n == 1) {
		printf("����%d : %c ==> %c\n",n, src, des);
		return;
	}
	HanoiTowerMove(n - 1, src, des, sub);       // 1�� ��� : ���� ��հ� ������ ����� ����
	printf("����%d : %c ==> %c\n", n, src, des);
	HanoiTowerMove(n - 1, src, des, sub);     // 2�� ���  : ���� ��հ� ��� ����� ����                                                                                                                                                                                                                                                               
}


int mian(){
	
	HanoiTowerMove(2, 'A', 'B', 'C');
					//( ���� ����, ��߱��, �������, ���������)
	}