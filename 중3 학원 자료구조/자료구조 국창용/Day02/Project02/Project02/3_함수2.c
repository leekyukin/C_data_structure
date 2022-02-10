#include<stdio.h>

void Hello(int n) {	// 함수의 매개변수 : 호출시 전달받은 값을 저장하는 변수
					// 매개변수는 함수 내부 코드에서 사용하기 위한 값, 외부에서 전달받는 값
	
	for (int i = 1; i <= n; i++) {
		printf("%d : Hello\n", i);
	}
	printf("\n");
}

int main() {
	Hello(3);	// 함수의 전달인자(= 전달값)

	Hello(7);


	int n;
	printf("횟수 : ");
	scanf_s("%d", &n);

	Hello(n);

	// 팁)
	// 함수의 전달인자와 매개변수의 개수 및 자료형은 일치시킨다
}