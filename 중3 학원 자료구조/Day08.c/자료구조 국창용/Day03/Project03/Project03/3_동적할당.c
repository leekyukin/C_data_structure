#include<stdio.h>
#include<stdlib.h>		// 여기에 동적할당 관련 함수가 있다


int main() {
	int num = 10;		// 정적 할당

	int* pnum = (int*)malloc(sizeof(int));

	*pnum = 100;
	printf("*pnum = %d\n", *pnum);

	free(pnum);		// 동적할당된 공간은 프로그램이 끝나도 사라지지 않는다
					// 꼭, 다쓰고 제거를 해줘야함

}