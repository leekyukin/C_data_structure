#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct person {
	char name[10];		// 이름
	int age;			// 나이
	double height;		// 키
	char address[20];	// 주소
}Person;

void printPerson(Person* p1) {
	printf("이름 : %s\n", p1->name);
	printf("나이 : %d\n", p1->age);
	printf("신장 : %.1lf\n", p1->height);
	printf("주소 : %s\n", p1->address);
}

Person* getPerson() {
	Person* tmp = (Person*)malloc(sizeof(Person));

	strcpy(tmp->name, "이름 없음");
	tmp->age = 0;
	tmp->height = 0;
	strcpy(tmp->address, "주소 없음");

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

	strcpy(p1->name, "이름 없음");
	p1->age = 0;
	p1->height = 0;
	strcpy(p1->address, "주소 없음");

	printPerson(p1);
	printf("\n");

	Person* p2 = getPerson();
	printPerson(p2);
	printf("\n");

	Person* p3 = getPerson2("홍길동", 15, 171.1, "부산");
	printPerson(p3);

	free(p1);
	free(p2);
	free(p3);
}