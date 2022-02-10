#include <stdio.h>
#define swap(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
int tmp, count;

int partition(int list[], int left, int right) {

	int low = left;
	int high = right + 1;
	int pivot = list[left];

	do {
		do {
			low++;
		} while (list[low] < pivot);
		do {
			high--;
		} while (list[high] > pivot);
		if (high > low) swap(list[high], list[low], tmp);
	} while (high > low);
	swap(list[high], list[left], tmp);
	return high;
}

void quickSort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quickSort(list, q + 1, right);
		quickSort(list, left, q - 1);
	}
	count++;
}

int main(void) {
	int list[7] = { 1,2,7,4,34,2,1 };

	quickSort(list, 0, 6);


	for (int i = 0; i < 7; i++)
		printf("%d ", list[i]);
}