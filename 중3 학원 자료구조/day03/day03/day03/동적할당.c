#include<stdio.h>
#include<stdlib.h>

int main() {
	int num = 10;                      // ���� �Ҵ�

	int* pnum = (int*)malloc(sizeof(int));

	*pnum = 100;

	printf("*pnum = %d\n", *pnum);

	free(pnum);    // �����Ҵ�� ������ ���α׷��� ������ ������� �ʴ´�
						// ��, �پ��� ���Ÿ� �������


}