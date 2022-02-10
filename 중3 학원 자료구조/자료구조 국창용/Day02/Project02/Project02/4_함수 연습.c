#include<stdio.h>


int total(int n) {
	int sum = 0;

	for (int i = 1; i <= n; i++) {
		sum += i;
	}

	return sum;
}

void star(n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("*");
		}
		printf("\n");
	}
}

int prime(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}


int main() {
	
	int n;

	printf("1.���� �Է� : ");
	scanf_s("%d", &n);

	printf("1 ~ %d������ �� : %d\n\n", n, total(n));


	printf("2.���� �Է� : ");
	scanf_s("%d", &n);

	star(n);	// ������ ��ŭ n x n ����⸦ ����ϴ� �Լ�

	
	printf("\n3.���� �Է� : ");
	scanf_s("%d", &n);

	// prime(n)  : �Ҽ��� 1�� ��ȯ
	//		       �ƴϸ� 0�� ��ȯ

	if (prime(n)) {
		printf("�Ҽ� �Դϴ�\n");
	}

	else {
		printf("�Ҽ��� �ƴմϴ�\n");
	}


}