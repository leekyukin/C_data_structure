#include<stdio.h>

int fac(int n) {
	if (n == 1) {
		return 1;
	}

	return n * fac(n - 1);

//  ���1 : return 3 * (n - 1)
//	���2 :               2 * (n - 1)
//  ���3 :                      1 
}

int main() {

	printf("3! = %d\n", fac(3));
}