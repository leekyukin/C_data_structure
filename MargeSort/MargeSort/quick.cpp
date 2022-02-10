#include <stdio.h>
#define swap(x,y,t) ((t)=(x),(x)=(y), (y)=(t))

int partition(int list[], int left, int right) {

	int low = left+1;
	int high = right;
	int pivot = list[left];
	int tmp;

	while (low < high) {
		 while (list[low] < pivot) {
			low++;
		}
		while (list[high] > pivot) {
			high++;
		}
		if (low < high)
			swap(list[low], list[high], tmp);
	} 
	swap(list[left], list[high], tmp);
	return high;
}

void QuickSort(int list[], int left, int right) {

	if (left < right) {
		int q = partition(list, left, right);
		QuickSort(list, left, q - 1);
		QuickSort(list, q + 1, right);
	}
}

int main(void) {

	int p, list[64];
	scanf_s("%d", &p);

	for (int i = 0; i < p; i++) {
		scanf_s("%d", &list[i]);
	}

	QuickSort(list, 0, p);


	for (int i = 0; i < p; i++) {
		printf("%d ", list[i]);
	}

}