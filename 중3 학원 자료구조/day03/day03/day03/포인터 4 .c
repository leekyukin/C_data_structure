#include<stdio.h>

int main() {

	int arr[5] = { 4,8,2,7,6 };
	int* p;

	p = arr;  // 배열의 이름 자체는 시작주소를 의미한
	printf("arr = %p\n", arr);
	printf("p = %p\n", p);

	printf("*arr = % d\n", *arr);
	printf("*p = %d\n\n", *p)

	printf("arr + 1 = %p\n", arr+1);
	printf("*arr + 1 = %d\n", *arr + 1);
	printf("*(arr + 1) = %d\n",*( arr+1));

	for (int i = 0; i < 5; i++) {
		// printf("%d ", arr[i]);
		printf("%d", *(arr + i));
	}


}