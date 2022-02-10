#include <stdio.h>

void sort(int list[], int size) {
	int i, j, k;

	for (i = 1; i < size; i++) {
		k = list[i];
		for(j = i - 1; j >= 0 && list[j] > k; j--)

	}


}

int main(void) {
	int list[8] = { 0,3,2,3,4,1,2,2};

	sort(list, 8);
	for (int i = 0; i < 8; i++)
		printf("%d ", list[i]);

}