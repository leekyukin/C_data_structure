#include <stdio.h>

int main() {
	int n; printf("정수 입력 : "); scanf_s("%d", &n);
	
	while (n != 0) {
		printf("%d", n % 10);
		n /= 10;
	}




	return 0;
}