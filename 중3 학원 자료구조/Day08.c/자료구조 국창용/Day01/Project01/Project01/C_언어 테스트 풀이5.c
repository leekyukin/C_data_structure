#include<stdio.h>

typedef struct person {
	char name[20];
	int age;
	double height;
}Person;

typedef unsigned int uint;

void printPerson(Person p) {
	printf("이름 : %s\n", p.name);
	printf("나이 : %d\n", p.age);
	printf("신장 : %.1lf\n\n", p.height);
}

int main() {
	Person p2 = { "홍길동", 25, 176.3 };

	printPerson(p2);

	Person p3 = { "김길동", 17, 172.1 };

	printPerson(p3);
}