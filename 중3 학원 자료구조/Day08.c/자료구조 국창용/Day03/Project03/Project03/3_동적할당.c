#include<stdio.h>
#include<stdlib.h>		// ���⿡ �����Ҵ� ���� �Լ��� �ִ�


int main() {
	int num = 10;		// ���� �Ҵ�

	int* pnum = (int*)malloc(sizeof(int));

	*pnum = 100;
	printf("*pnum = %d\n", *pnum);

	free(pnum);		// �����Ҵ�� ������ ���α׷��� ������ ������� �ʴ´�
					// ��, �پ��� ���Ÿ� �������

}