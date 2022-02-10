#include<stdio.h>

void swap(int* n1, int* n2) {
	int tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

int main() {
	int n1 = 10, n2 = 20;
	
	printf("변환 전) n1 = %d, n2 = %d\n", n1, n2);

	swap(&n1, &n2);

	printf("변환 후) n1 = %d, n2 = %d\n", n1, n2);
}