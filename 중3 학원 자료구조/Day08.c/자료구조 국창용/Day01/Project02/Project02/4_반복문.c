#include<stdio.h>

// 반복문 
// while		: 주로 불특정 횟수 반복에 자주 사용된다
// for			: 주로 특정 횟수 반복에 자주 사용된다
// do ~ while	: while문에서 조건식과 종속문장의 순서가 뒤바뀐것

int main() {
	// for(초기값; 조건식; 증감식) { 종속문장; }
	//       1       2      3          4
	int i;

	for (i = 1; i <= 10; i++) {
		printf("%d ", i);
	}
	printf("\n");
	
	printf("반복 후 i = %d\n", i);

	// 실행순서 : 1 -> 2 -> 4 -> 3 -> 2 -> 4 -> 3 ......
}