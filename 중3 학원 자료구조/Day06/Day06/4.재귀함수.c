#include<stdio.h>
#include<stdlib.h>

// 재귀함수 (recursice function)
// ㄴ> 함수 내부에서 본인 함수를 호출하는 구조

void func(int n) {  
	if (n == 0) {  // 재귀함수는 종료되야하는 조건이 필요하다.
	
		return;
	}
	printf("%d ", n);    //재귀함수보다 위 => 재귀 하기전 실행
	func(n-1);            // 재귀구간 (★) 

    printf("%d ", n);          // 재귀함수보다 아래=>재귀가 풀리면서 실행되는 구간

}

int main() {
	func(3);
}