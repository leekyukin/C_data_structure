#include <stdio.h>


void sort(int list[], int n) {
	
	
}

int main(void) {
	int list[4] = { 1,9,2,7 };
	int i, j, n = 4, tmp, key;

	for (int i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", list[i]);
}