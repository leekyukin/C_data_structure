#include <stdio.h>

int sort(int arr[], int n) {
	int k;
	for (int i = 0; i < n; i++) {
		k = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[k])
				k = j;
		}
		int tmp = arr[i];
		arr[i] = arr[k];
		arr[k] = tmp;
	}
}

int main(void) {
	int list[8] = { 1,9,2,7,8,3,7,5 };
	sort(list, 8);

	for (int i = 0; i < 8; i++)
		printf("%d", list[i]);
}