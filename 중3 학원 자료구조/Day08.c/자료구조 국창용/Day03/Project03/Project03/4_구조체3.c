#include<stdio.h>

// 구조체 재정의는 선언시 바로 적용 가능

typedef struct po2 {
	int x, y;	// int x;
				// int y;
}Po2;

void printPoint(Po2 p) {
	printf("좌표 : (%d, %d)\n", p.x, p.y);
}

Po2 addPoint(Po2 p1, Po2 p2) {
	Po2 tmp;

	tmp.x = p1.x + p2.x;
	tmp.y = p1.y + p2.y;

	return tmp;
}

void swap(Po2* p1, Po2* p2) {
	Po2 tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int main() {
	Po2 p1 = { 1,2 };
	Po2 p2 = { 4,9 };
	Po2 p3;

	p3 = p1;	// 멤버 변수가 1:1로 복사가 된다
	
	printPoint(p1);		// 좌표 : (1, 2)
	printPoint(p2);
	printPoint(p3);

	p3 = addPoint(p1, p2);		// 전달한 두 좌표를 더해서 반환하는 함수
	printPoint(p3);		// 좌표 : (5, 11)

	// 추가 문제) p1과 p2의 좌표를 서로 교환하는 swap 구현
	printf("\n");
	swap(&p1, &p2);

	printPoint(p1);
	printPoint(p2);
}