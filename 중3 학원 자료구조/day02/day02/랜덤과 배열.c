
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {

	int num = rand();   //rand()  :  2^15(0 ~ 32767)������ ������ ���� ��ȯ�ϴ� �Լ�

	srand(time(NULL));

	for (int i = 1; i <= 10; i++) {
		num = rand()%100;  
		printf("%d\t", num);
	}



}
