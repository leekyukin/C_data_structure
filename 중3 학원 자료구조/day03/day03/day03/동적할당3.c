# include<stdio.h>
# include<stdlib.h>

int main() {
	int num = 5;

	//�����Ҵ� �迭
	// int arr[num];    // �����Ҵ� �迭�� ũ�⿡ ������ �ۼ� �Ұ���
	int arr[5];

	// �����Ҵ� �迭 
	int* parr = (int*)malloc(sizeof(int) * num);// �����Ҵ��� �����߿� ũ�Ⱑ �ٲ�� �ִ�.

	for (int i = 0; i < num; i++) {
		*(parr + i) = i + 1;
	}

	for (int i = 0; i < num; i++) {
		printf("%d ", *(parr + i));
	}
	printf("\n");


	free(parr);

}