#include<stdio.h>

int main() {
	int num = 5;

	int* pnum;
	pnum = &num;      // pnum -> num
	
	printf("num = %p\n", pnum);
	printf("*pnum = %d\n", *pnum);

	// �����͸� ��ﶧ ��ȣ��
	// 1. & (ampersend) : ������ �տ� �پ �޸� �ּҸ� �ǹ��ϴ� ��ȣ
	// 2. * (askerisk)
	// ��> 1. ������ ������ ����� ���
	// ��> 2. �ּ� �տ� �پ �޸� �ּ� ���� �����͸� ����
}