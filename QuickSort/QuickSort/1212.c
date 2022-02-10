#include <stdio.h>
#define swap(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int tmp, count, size;

int partition(int list[], int left, int right) {

	int low = left+1;
	int high = right;
	int pivot = list[left];

	while (low < high) {
		while (list[low] > pivot)
			low++;
		while (list[high] < pivot)
			high--;
		if (low < high) swap(list[low], list[high], tmp);
	}
	swap(list[left], list[high], tmp);
	printf("%d´Ü°è:",++count);
	for (int l = 0; l < size; l++)
		printf("%d ", list[l]);
	printf("\n");
	return high;
}

void sort(int list[], int left, int right) {

	if (left < right) {
		int p = partition(list, left, right);
		sort(list, left, p - 1);
		sort(list, p + 1, right);
	}
}


int main(void) {
	scanf_s("%d", &size);
	int list[64];
	for (int i = 0; i < size; i++)
		scanf_s("%d", &list[i]);


	sort(list, 0, size - 1);
}