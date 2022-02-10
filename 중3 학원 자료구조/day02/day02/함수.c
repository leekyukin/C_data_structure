#include <stdio.h>

void Hello() {
	for (int i = 0; i < 5;  i++) {
	printf("%d : Hello world!!!\n", i);
}
printf("\n");
	}

int main() {

	Hello();  // 함수의 호출 : 함수의 기능(=코드)를 사용하겠다.

	return 0;
}


// 디버그 모드
// F11 :디버그모드 집입, 한줄씩 실행, 함수 진입(O)
// F10 :디버그모드 집입, 한줄씩 실행, 함수 진입(X)

