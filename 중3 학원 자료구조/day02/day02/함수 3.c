#include <stdio.h>
int adder(int n1, int n2) {
	int result;

	result = n1 + n2;
	
	return result;
}
int main() {
	int sum;

	sum = adder(10, 7);
	printf("sum = %d\n", sum);
	
	
	return 0;
}