#include<stdio.h>

typedef struct person {
	char name[20];
	int age;
	double height;
}Person;

typedef unsigned int uint;

void printPerson(Person p) {
	printf("�̸� : %s\n", p.name);
	printf("���� : %d\n", p.age);
	printf("���� : %.1lf\n\n", p.height);
}

int main() {
	Person p2 = { "ȫ�浿", 25, 176.3 };

	printPerson(p2);

	Person p3 = { "��浿", 17, 172.1 };

	printPerson(p3);
}