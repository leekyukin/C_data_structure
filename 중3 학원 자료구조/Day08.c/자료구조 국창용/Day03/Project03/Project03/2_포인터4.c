#include<stdio.h>

int main() {
	// �����Ϳ� �迭�� ����

	int arr[5] = { 4,8,2,7,6 };
	int* p;

	p = arr;	// �迭�� �̸� ��ü�� �����ּҸ� �ǹ��Ѵ�
	printf("arr = %p\n", arr);
	printf("p = %p\n", p);

	printf("*arr = %d\n", *arr);	// arr[0]
	printf("*p = %d\n\n", *p);

	printf("arr + 1 = %p\n", arr + 1);
	printf("*arr + 1 = %d\n", *arr + 1);		// arr[0] + 1
	printf("*(arr + 1) = %d\n", *(arr + 1));	// arr[1]


	for (int i = 0; i < 5; i++) {
	//	printf("%d ", arr[i]);		// �ּ� �������� �Ʒ��� ���
		printf("%d ", *(arr + i));
	}
	printf("\n");
}