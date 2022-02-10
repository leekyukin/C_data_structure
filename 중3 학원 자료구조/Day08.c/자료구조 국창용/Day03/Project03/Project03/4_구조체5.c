#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct person {
	char name[10];		// �̸�
	int age;			// ����
	double height;		// Ű
	char address[20];	// �ּ�
}Person;

void printPerson(Person* p1) {
	printf("�̸� : %s\n", p1->name);
	printf("���� : %d\n", p1->age);
	printf("���� : %.1lf\n", p1->height);
	printf("�ּ� : %s\n", p1->address);
}

Person* getPerson() {
	Person* tmp = (Person*)malloc(sizeof(Person));

	strcpy(tmp->name, "�̸� ����");
	tmp->age = 0;
	tmp->height = 0;
	strcpy(tmp->address, "�ּ� ����");

	return tmp;
}

Person* getPerson2(char* n, int a, double h, char* ad) {
	Person* tmp = (Person*)malloc(sizeof(Person));

	strcpy(tmp->name, n);
	tmp->age = a;
	tmp->height = h;
	strcpy(tmp->address, ad);

	return tmp;
}

int main() {
	Person* p1 = (Person*)malloc(sizeof(Person));

	strcpy(p1->name, "�̸� ����");
	p1->age = 0;
	p1->height = 0;
	strcpy(p1->address, "�ּ� ����");

	printPerson(p1);
	printf("\n");

	Person* p2 = getPerson();
	printPerson(p2);
	printf("\n");

	Person* p3 = getPerson2("ȫ�浿", 15, 171.1, "�λ�");
	printPerson(p3);

	free(p1);
	free(p2);
	free(p3);
}