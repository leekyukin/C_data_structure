#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {

	int num;
	srand(time(NULL));

	// 1. 0~99 ������ ���� �̱�
	for (int i = 1; i <= 10; i++) {
		num = rand()%100;
		printf("%d  ", num);
	}
	printf("\n\n");

	// 2. 1~45������ ���� �̱�
	for (int i = 1; i <= 10; i++) {
		num = rand() % 45+1;
		printf("%d  ", num);
	}
	printf("\n\n");


	// 3. 7~38 ������ ���� �̱�
	for (int i = 1; i <= 10; i++) {
		num = rand() % 32 + 7;
		printf("%d  ", num);
	}
	printf("\n\n");

}