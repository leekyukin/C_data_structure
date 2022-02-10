#include <stdio.h>
#define swap(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int count, n;
int partition(int list[], int left, int right) {

	int low = left+1;
	int high = right;
	int pivot = list[left];
	int tmp;
	while (low <= high) {
		while (list[low] > pivot)
			low++;
		while (list[high] < pivot)
			high--;
		if (low < high) swap(list[low], list[high], tmp);
	}
	swap(list[left], list[high], tmp);
	printf("%d´Ü°è:", ++count);
	for(int i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return high;
}
void sort(int list[], int left, int right) {

	if (left < right) {
		int p = partition(list, left, right);
		sort(list, left, p-1);
		sort(list, p + 1, right);
	}

}

int main(void) {
	
	
	scanf_s("%d", &n);
	int list[64];
	for (int i = 0; i < n; i++)
		scanf_s("%d", &list[i]);

	/*int list[10] = { 1,92,394,2,34,2,3,42,3,4 };*/
	sort(list, 0, n-1);
}