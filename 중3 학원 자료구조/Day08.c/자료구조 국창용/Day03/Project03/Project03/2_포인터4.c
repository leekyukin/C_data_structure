#include<stdio.h>

int main() {
	// 포인터와 배열의 관계

	int arr[5] = { 4,8,2,7,6 };
	int* p;

	p = arr;	// 배열의 이름 자체는 시작주소를 의미한다
	printf("arr = %p\n", arr);
	printf("p = %p\n", p);

	printf("*arr = %d\n", *arr);	// arr[0]
	printf("*p = %d\n\n", *p);

	printf("arr + 1 = %p\n", arr + 1);
	printf("*arr + 1 = %d\n", *arr + 1);		// arr[0] + 1
	printf("*(arr + 1) = %d\n", *(arr + 1));	// arr[1]


	for (int i = 0; i < 5; i++) {
	//	printf("%d ", arr[i]);		// 주소 연산으로 아래에 출력
		printf("%d ", *(arr + i));
	}
	printf("\n");
}