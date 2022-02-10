#include <stdio.h>
#define swap(x,y,t) ((t) = (x), (x) = (y), (y)=(t))
int count;
int partition(int list[], int left, int right) {
	int tmp;
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
		if(low < high)
			swap(list[low], list[high], tmp);
	} while (low < high);

	swap(list[high], list[left], tmp);
	return high;
}

void quickSort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quickSort(list, left, q - 1);
		quickSort(list, q + 1, right);
	}
	count++;
}


int main(void) {

	int list[9] = { 2,9,3,7,4,5,6,1,2 };

	quickSort(list, 0, 8);
	for (int i = 0; i < 8; i++)
		printf("%d ", list[i]);

}