#include<stdio.h>
#include<stdlib.h>	// random() 함수가 있다
#include<time.h>

int main() {

	int num;	

	srand(time(NULL));

	for (int i = 1; i <= 10; i++) {
		num = rand();	// rand()  :   2^15(0 ~ 32767) 까지의 무작위 수를 반환하는 함수
		printf("%d\n", num);
	}
}