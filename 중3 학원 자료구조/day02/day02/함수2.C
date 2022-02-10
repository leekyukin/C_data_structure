#include <stdio.h>

void Hello(int n) {
	for (int i = 1; i <= n; i++) {
		printf("%d : Hello\n", i);
	}
	printf("\n");
}

int main() {
	Hello(3);

	int n;
	printf("È½¼ö : ");
	scanf_s("%d", &n);
	return 0;
}