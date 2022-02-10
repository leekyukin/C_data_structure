#include<stdio.h>

// 재정의 구문 : 긴 이름의 자료형이나, 자료형에 의미를 부여하기 위해서 자료형을 다시 쓰는 것
typedef unsigned int uint;
typedef int elements;

int main() {
	int it = 2000000000;
	unsigned int uit = 4000000000;

	uint uit2 = 3000000000;

	printf("it = %d\n", it);
	printf("uit = %u\n", uit);
	printf("uit2 = %u\n", uit2);

}