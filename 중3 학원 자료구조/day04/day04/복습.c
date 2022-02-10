#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//구조체 선언
// 1. Person으로 사용할 수 있게 재정의 하면서 선언한다.
// 2. 내부 맴버는 이름(10),나이,키를 가진다

typedef struct person {
	char name[10];
	int age;
	double height;
}Person;

void printPerson(Person* p) {
	printf("이름 : %s\n", p->name);
	printf("나이 : %d\n", p->age);
	printf("신장 : %2.lf",p->height);
}

Person* getPerson() {
	Person* tmp = (Person*)malloc(sizeof(Person));
	strcpy(tmp->name, "이름 없음"); // 주소라서 "->"씀 , 문자열 복사 : strcpy
	tmp->age = 0;
	tmp->height = 0;
	return tmp; // 함수랑 자료형이 같아야함 
}

int main() {

	Person* p1 = (Person*)malloc(sizeof(Person));
	// 위의 구문은 공간만 생성하고 초기화 되지않는단점이 있다
	// 이를 보완할 수 있는 getPerson()함수를 구현

	Person* p2 = getPerson(); // 좌변 우변 자료형이 같아야 함 그래서 함수도 Person 포인터

	printPerson(p2);       // 이름 : 이름 없음
									// 나이 : 0
									// 신장 : 0

	free(p1);
	free(p2);
}