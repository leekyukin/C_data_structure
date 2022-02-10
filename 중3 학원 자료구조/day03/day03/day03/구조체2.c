#include<stdio.h>
#include<string.h>

// 변수 : 데이터를 저장하는 공간, 단일 공간
// 배열 : 같은 자료형으로 메모리상 연속된 공간
// 구조체 : 다른 여러 자료형을 묶어놓은 형태

struct person {
	char name[10];   // 이름
	int age;				  // 나이
	double height;  // 키
};

void printPerson(struct person p) {
	printf("%s,%d,%1.lf\n", p.name, p.age, p.height);
}

typedef struct person Person;

int main() {
	struct person p1 = { "홍길동",25,175.5 };

	// printf("p1 = %s,%d,%lf\n", p1.name, p1.age, p1.height);
	printPerson(p1);

	Person p2 = { "김길동",15,167.2 };
	printPerson(p2);

	Person p3;
	p3.age = 21;

	printPerson(p3);

}