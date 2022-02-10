#include<stdio.h>

// 구조체 재정의는 선언시 바로 적용 가능

typedef struct po2 {
	int x, y;   // int x;
				 //  int y;
}Po2;

void printfPoint(Po2 p) {
	printf("좌표 : (%d, %d)\n", p.x, p.y);
}
int main() {
	Po2 p1 = { 1,2 };
	Po2 p2 = { 4,9 };
	Po2 p3;

	p3 = p1;    // 맴버 변수가  1:1로 복사가 된다

	printfPoint(p1);
	printfPoint(p2);
	printfPoint(p3);

	/*p3 = addPoint(p1, p2);  */    // 전달한 두 좌표를 더해서 반환하는 함수
	printPoint(p3);               // 좌표 : (5,11)

}