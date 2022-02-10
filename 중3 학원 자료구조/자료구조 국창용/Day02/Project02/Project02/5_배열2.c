#include<stdio.h>
#define MAX 5		// 매크로 상수 : 상수값에 이름을 붙여놓은 것
					// 치환 구문이라고도 한다

int main() {

	int arr[MAX];
	int count = 10;

	// 채우는 반복
	for (int i = 0; i < MAX; i++) {
		arr[i] = count;
		count += 10;
	}

	// 출력하는 반복
	printf("arr = ");

	for (int i = 0; i < MAX; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}