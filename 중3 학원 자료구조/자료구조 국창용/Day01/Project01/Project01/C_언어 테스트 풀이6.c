#include<stdio.h>
#include<stdlib.h>	// �����Ҵ� �Լ��� �ִ� ��� ����

int main() {
	int* ptr;

	ptr = (int*)malloc(sizeof(int));

	*ptr = 10;

	printf("ptr�� ����Ű�� ���� �� : %d\n", *ptr);

	free(ptr);
}