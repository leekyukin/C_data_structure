#include <stdio.h>



int main(void) {
	printf("ǥ�� ��� ���� �Դϴ�\n");

	char word[10];
	int num;
	double pi;

	printf("�Է� ���� word : ");
	scanf_s("%s", word,sizeof(word));

	printf("word =%s\n\n", word);

	printf("�Է� ���� num : ");
	scanf_s("%d", &num);

	printf("num = %d\n\n", num);
	
	printf("�Է� ���� pt : ");
	scanf_s("%lf", &pi);

	printf("pi = %lf\n", pi);
	return 0;
}