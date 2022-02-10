#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ����ü ����
// 1. Person���� ����� �� �ְ� ������ �ϸ鼭 �����Ѵ�
// 2. ���� ����� �̸�(10), ����, Ű �� ������

typedef struct person {
	char name[10];
	int age;
	double height;
}Person;

Person* getPerson() {
	Person* tmp = (Person*)malloc(sizeof(Person));
	strcpy(tmp->name, "�̸� ����");
	tmp->age = 0;
	tmp->height = 0;

	return tmp;
}

void printPerson(Person* p) {
	printf("�̸� : %s\n", p->name);
	printf("���� : %d\n", p->age);
	printf("���� : %.1lf\n", p->height);
}

int main() {
	Person* p1 = (Person*)malloc(sizeof(Person));
	// ���� ������ ������ �����ϰ� �ʱ�ȭ �����ʴ� ������ �ִ�
	// �̸� ������ �� �ִ� getPerson()�Լ��� ����

	Person* p2 = getPerson();

	printPerson(p2);	// �̸� : �̸� ����
						// ���� : 0
						// ���� : 0

	free(p1);
	free(p2);
}