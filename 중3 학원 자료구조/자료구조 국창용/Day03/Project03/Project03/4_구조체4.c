#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct person {
	char name[10];
	int age;
	double height;
}Person;


int main() {
	Person p1 = { "ȫ�浿", 22, 173.3 };

	Person* pp;
	pp = &p1;		// pp -> p1

	printf("%s, %d, %.1lf\n", (*pp).name, (*pp).age, (*pp).height);
	printf("%s, %d, %.1lf\n", pp->name, pp->age, pp->height);

	// ����ü�� �ּҷ� ����� ������
	// 1. �����ͺ����� ���� ����(*) �� . �����ڷ� ����
	// 2. -> ������(arrow ������)�� ����

	printf("Person�� ũ�� : %d\n", sizeof(Person));

	Person* p = (Person*)malloc(sizeof(Person));

	strcpy(p->name, "��浿");
	p->age = 27;
	p->height = 181.5;

	printf("%s, %d, %.1lf\n", p->name, p->age, p->height);

	free(p);

}