#include<stdio.h>
#include<stdlib.h>	// random() �Լ��� �ִ�
#include<time.h>

int main() {

	int num;	

	srand(time(NULL));

	for (int i = 1; i <= 10; i++) {
		num = rand();	// rand()  :   2^15(0 ~ 32767) ������ ������ ���� ��ȯ�ϴ� �Լ�
		printf("%d\n", num);
	}
}