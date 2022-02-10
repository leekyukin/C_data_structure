#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct person {
	char name[10];
	int age;
	double height;
}Person;


int main() {
	Person p1 = { "홍길동", 22, 173.3 };

	Person* pp;
	pp = &p1;		// pp -> p1

	printf("%s, %d, %.1lf\n", (*pp).name, (*pp).age, (*pp).height);
	printf("%s, %d, %.1lf\n", pp->name, pp->age, pp->height);

	// 구조체의 주소로 멤버를 참조시
	// 1. 포인터변수를 먼저 참조(*) 후 . 연산자로 접근
	// 2. -> 연산자(arrow 연산자)로 접근

	printf("Person의 크기 : %d\n", sizeof(Person));

	Person* p = (Person*)malloc(sizeof(Person));

	strcpy(p->name, "김길동");
	p->age = 27;
	p->height = 181.5;

	printf("%s, %d, %.1lf\n", p->name, p->age, p->height);

	free(p);

}