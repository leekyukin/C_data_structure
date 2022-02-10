#include<stdio.h>

int sum(int n) {
	if (n == 1) {
		return 1;
	}
	return n + sum(n - 1);
} 

int power(int n1, int n2) {
	if (n2 == 0) {
		return 1;
	}

	return n1 * power(n1, n2 - 1);
}

int fibo(int n) {
	if (n == 1)    return 0;
	if (n == 2)    return 1;

	return fivo(n - 1) + fibo(n - 2);
}



int main() {

	printf("1. %d\n", sum(10));

	printf("2. %d\n", power(2, 3));

	printf("3. %d\n", fibo(3));

	for (int i = 1; i < 20; i++) {
		printf("%d ", fibo(i));
	}
}