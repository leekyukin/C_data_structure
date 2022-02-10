# include<stdio.h>
# include<stdlib.h>

int main() {
	int num = 5;

	//정적할당 배열
	// int arr[num];    // 정적할당 배열은 크기에 변수를 작성 불가능
	int arr[5];

	// 동적할당 배열 
	int* parr = (int*)malloc(sizeof(int) * num);// 동적할당은 실행중에 크기가 바뀔수 있다.

	for (int i = 0; i < num; i++) {
		*(parr + i) = i + 1;
	}

	for (int i = 0; i < num; i++) {
		printf("%d ", *(parr + i));
	}
	printf("\n");


	free(parr);

}