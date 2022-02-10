#include <stdio.h>
#define MAX 5  // 매크로 상수  : 상수값의 이름을 붙여놓은것
			   // 치환 구문이라고도 한다
int main() {
	
	int arr[MAX]; 
	int count = 10;

	for (int i = 0; i < MAX; i++) {
		arr[i] = count;
		count += 10;
	}

	printf("arr = ");

	for (int i = 0; i < MAX; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
}