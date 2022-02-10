#include<stdio.h>
#include<string.h>

// 변수 : 데이터를 저장하는 공간, 단일 공간
// 배열 : 같은 자료형으로 메모리상 연속된 공간
// 구조체 : 다른 여러 자료형을 묶어놓은 형태

struct person {
	char name[10];	// 이름
	int age;		// 나이
	double height;	// 키
};

typedef struct person Person;

void printPerson(Person p) {
	printf("%s, %d, %.1lf\n", p.name, p.age, p.height);
}

int main() {
	struct person p1 = { "홍길동", 25, 176.5 };

//	printf("p1 = %s, %d, %lf\n", p1.name, p1.age, p1.height);
	printPerson(p1);

	Person p2 = { "김길동", 15, 167.2 };
	printPerson(p2);

	Person p3;

//	p3.name = "고길동";	// 배열은 대입연산으로 데이터 복사 불가능

	strcpy(p3.name, "고길동");
	p3.age = 21;
	p3.height = 181.2;

	printPerson(p3);


	// ※ 문자열 함수
	// strlen("문자열") : 문자열 개수를 구해준다 (NULL값은 제외)
	// strcpy("문자열1", "문자열2") : 문자열2를 문자열1에 복사
	// strcmp("문자열1", "문자열2") : 문자열1과 문자열2가 동일한지 비교
	//								같으면 0을 반환, 문자열1이 크면 1을 반환, 문자열1이 작으면 -1를 반환
}