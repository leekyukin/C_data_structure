#include<stdio.h>
#include<stdlib.h>	// 동적할당 함수가 있는 헤더 파일

int main() {
	int* ptr;

	ptr = (int*)malloc(sizeof(int));

	*ptr = 10;

	printf("ptr이 가리키는 공간 값 : %d\n", *ptr);

	free(ptr);
}