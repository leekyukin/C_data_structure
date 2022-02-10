#include<stdio.h>

int main() {
	char name[20];
	int age;
	double height;

	printf("==== 입력 ====\n");
	printf("이름 : ");
	scanf("%s", name);

	printf("나이 : ");
	scanf("%d", &age);

	printf("신장 : ");
	scanf("%lf", &height);

	printf("==== 출력 ====\n");
	printf("이름 : %s\n", name);
	printf("나이 : %d 세\n", age);
	printf("신장 : %.1lf cm\n", height);

}