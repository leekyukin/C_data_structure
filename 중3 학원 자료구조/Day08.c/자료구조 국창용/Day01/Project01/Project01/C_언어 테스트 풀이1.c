#include<stdio.h>

int main() {
	char name[20];
	int age;
	double height;

	printf("==== �Է� ====\n");
	printf("�̸� : ");
	scanf("%s", name);

	printf("���� : ");
	scanf("%d", &age);

	printf("���� : ");
	scanf("%lf", &height);

	printf("==== ��� ====\n");
	printf("�̸� : %s\n", name);
	printf("���� : %d ��\n", age);
	printf("���� : %.1lf cm\n", height);

}