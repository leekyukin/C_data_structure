#include <stdio.h>
#define swap(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int size, count;

int partition(int list[], int left, int right) {

	int low = left;
	int high = right + 1;
	int pivot = left;
	int tmp;

	do {
		do {
			low++;
		} while (list[low] < pivot);
		do {
			high--;
		} while (list[high] > pivot);
		if (low < high) swap(list[low], list[high], tmp);
	} while (low < high);
	swap(list[left], list[high], tmp);
	return high;
}

void QuickSort(int list[], int left, int right) {

	if (left < right) {
		int p = partition(list, left, right);
		QuickSort(list, left, p - 1);
		QuickSort(list, p + 1, right);
	}

}


int main(void) {
	scanf_s("%d", size);
	int list[64];
	for (int i = 0; i < size; i++)
		scanf_s("%d", &list[i]);

	QuickSort(list, 0, size - 1);
}