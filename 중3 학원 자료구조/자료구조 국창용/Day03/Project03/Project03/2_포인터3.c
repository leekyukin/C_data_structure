#include<stdio.h>

int main() {
	int num = 10;		// 4byte
	double db = 3.14;	// 8byte

	int* pnum = &num;	// 4byte
	double* pdb = &db;	// 4byte	=> ������ �ּҸ� ����Ǳ� ����

	printf("pnum - 1 = %p, pnum = %p, pnum + 1 = %p\n", pnum - 1, pnum, pnum + 1);
	// int* �� �ּ� ������ ��ĭ�� 4byte�� �ν�

	printf("pdb - 1 = %p, pdb = %p, pdb + 1 = %p\n", pdb - 1, pdb, pdb + 1);
	// double* �� �ּ� ������ ��ĭ�� 8byte�� �ν�
}