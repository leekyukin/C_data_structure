#include <stdio.h>
#define swap(x,y,t) ((t)=(x), (x)=(y), (y)=(t))


int partition(int list[], int left, int right) {

	int low = left + 1;
	int high = right;
	int pivot = list[left];
	int tmp;

	while (low < high) {
		while (list[low] < pivot)
			low++;
		while (list[high] > pivot)
			high--;
		if (low < high) swap(list[high], list[low], tmp);
	}
	swap(list[left], list[high], tmp);
	return high;
}

void sort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		sort(list, left, q - 1);
		sort(list, q + 1, right);
	}
}

int main(void) {
	
	int list[10] = { 5,1,3,5,3,6,3,5,1,10 };
	sort(list, 0, 9);

	for (int i = 0; i < 10; i++)
		printf("%d ", list[i]);

}