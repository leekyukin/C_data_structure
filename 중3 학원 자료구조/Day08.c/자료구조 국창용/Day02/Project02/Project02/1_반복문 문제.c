#include<stdio.h>

int main() {
	int total = 0;

	for (int i = 1; i <= 1000; i++) {
		if (i % 3 == 0 && i % 5 == 0) {}

		else if (i % 3 == 0) {
			continue;
		}

		total += i;		// total = total + i;

	//	printf("�����) i = %d, total = %d\n", i, total);
	}

	printf("��� : %d\n", total);
}