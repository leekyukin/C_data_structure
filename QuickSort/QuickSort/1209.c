#include <stdio.h>
#define swap(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
int tmp;
int partition(int list[], int left, int right) {

	int low = left+1;
	int high = right;
	int pivot = list[left];

	while (low < high) {
		while (list[low] > pivot) {
			low++;
		}
		while (list[high] < pivot) {
			high--;
		}
		if (low < high) swap(list[left], list[high], tmp);
	}
	swap(list[left], list[high], tmp);
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

	int size;
	scanf_s("%d", &size);
	int list[100];
	for (int i = 0; i < size; i++)
		scanf_s("%d", &list[i]);
	sort(list, 0, size - 1);
	for (int i = 0; i < size; i++)
		printf("%d ", list[i]);


}