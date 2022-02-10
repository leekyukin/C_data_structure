#include <stdio.h>

int sort(int list[], int n) {

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (list[j] > list[j + 1]) {
				int tmp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = tmp;
			}
		}
	}
}

int main(void) {

	int list[8] = { 1,9,2,7,8,3,7,5 };
	sort(list, 8);

	for (int i = 0; i < 8; i++)
		printf("%d ", list[i]);

}