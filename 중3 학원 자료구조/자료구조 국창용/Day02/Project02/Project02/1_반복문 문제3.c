#include<stdio.h>

int main() {
	int num;
	int count = 0;

	printf("1.���� �Է� : ");
	scanf_s("%d", &num);

	for (int i = 1; i <= num; i++) {
		if (num % i == 0) {
			printf("%d ", i);
			count++;
		}
	}
	printf("(%d��)\n\n", count);


	printf("2.���� �Է� : ");
	scanf_s("%d", &num);
	count = 0;

	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			printf("������� => �Ҽ��ƴ�\n");
			count++;
			break;
		}
	}

	if (count == 0) {
		printf("������� => �Ҽ�\n");
	}

}