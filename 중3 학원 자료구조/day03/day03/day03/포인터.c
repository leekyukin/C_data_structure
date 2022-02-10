#include<stdio.h>

int main() {
	int num = 5;

	int* pnum;
	pnum = &num;      // pnum -> num
	
	printf("num = %p\n", pnum);
	printf("*pnum = %d\n", *pnum);

	// 포인터를 배울때 기호들
	// 1. & (ampersend) : 데이터 앞에 붙어서 메모리 주소를 의미하는 기호
	// 2. * (askerisk)
	// ㄴ> 1. 포인터 변수를 선언시 사용
	// ㄴ> 2. 주소 앞에 붙어서 메모리 주소 안의 데이터를 참조
}