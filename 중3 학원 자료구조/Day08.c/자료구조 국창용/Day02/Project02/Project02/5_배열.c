#include<stdio.h>

// 변수 : 데이터를 저장하는 공간(= 단일 공간)
// 배열 : 같은 자료형으로 메모리상 연속된 공간

int main() {
	int n = 10;		// 일반 변수

	int arr[5] = { 10,20,30,40,50 };	// 배열
	//				0  1  2  3  4   (index : 배열의 순서 번호)

	printf("arr = %p\n", arr);			// 배열의 이름은 시작주소를 의미
	printf("0번째 : %d\n", arr[0]);		// 배열 데이터 참조는 index로 접근한다

	// 배열을 전체 출력하는 방식 => 반복문 밖에 없음
	printf("arr = ");

	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

}