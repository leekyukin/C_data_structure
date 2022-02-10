#include<stdio.h>

// 함수의 자료형 : 반환형, 함수의 실행 결과 데이터의 자료형을 의미
int adder(int n1, int n2) {
	int result;

	result = n1 + n2;

	return result;	// return 반환값;   해당값을 함수의 호출 위치로 되돌려준다(= 반환)
}


int main() {

	int sum;

	sum = adder(10, 7);						// 반환값을 저장
	printf("sum = %d\n", sum);

	printf("결과 : %d\n", adder(20, 4));		// 반환값을 곧장 사용

	// 즉, 반환형이 있는 함수를 사용시 저장하지 않거나 바로 활용하지 않으면 결과값을 버리는 행위
	// 반환형이 있는 함수 : char, int, float, double 등
	// 반환형이 없는 함수 : void

	sum = adder(adder(10, 2), adder(20, 3));	// 반환값을 다른 함수의 전달값으로 사용도 가능
	printf("sum = %d\n", sum);
}