#include <stdio.h>
#define swap(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
int count;
int partition(int list[], int left, int right) {
	int pivot, tmp, low, high;
	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do {
			low++;
		} while (list[low] < pivot);
		do {
			high--;
		} while (list[high] > pivot);

		if (low < high) {
			swap(list[low], list[high], tmp);
		}
	} while (low < high);
	swap(list[left], list[high], tmp);
	return high;
}

void quicksort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quicksort(list, left, q - 1);
		quicksort(list, q + 1, right);
	}
	count++;
}

int main(void) {
	int list[11] = { 1,5,2,3,5,6,3,4,5,7,3 };
	quicksort(list, 0, 10);
	for (int i = 0; i < 11; i++)
		printf("%d ", list[i]);
}