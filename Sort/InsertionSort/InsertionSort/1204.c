#include <stdio.h>

int insertionSort(int list[], int size) {
	int key;
	int j;
	for (int i = 1; i < size; i++) {
		key = list[i];
		for (j = i - 1; list[j] > key && j >= 0; j--)
			list[j + 1] = list[j];
		list[j + 1] = key;
	}

}

int main(void) {

	int list[12] = { 11,12,9,91,4,10,111,4,3,5,19,1001 };
	insertionSort(list, 12);
	for (int i = 0; i < 12; i++) {
		printf("%d ", list[i]);
	}

}