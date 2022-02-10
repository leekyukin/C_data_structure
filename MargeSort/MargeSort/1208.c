#include <stdio.h>
int sorted[100], count;

void merge(int list[], int left, int mid, int right) {
	
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {

		if (list[i] >= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	printf("%d´Ü°è : ", ++count);
	
	if (i > mid) {
		for (l = j; l <= right; l++) {
			sorted[k++] = list[l];
			printf("%d ", sorted[l]);
			
		}
	}
	else {
		for (l = i; l <= mid; l++) {
			sorted[k++] = list[l];
			printf("%d ", sorted[l]);
		}
	}
	
	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
		printf("%d ", list[l]);
	}
		
	printf("\n");
}

void mergeSort(int list[], int left, int right) {

	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		mergeSort(list, left, mid);
		mergeSort(list, mid + 1, right);
		merge(list, left, mid, right);
		
		
	}
	
	
	
}

int main(void) {
	int size;
	scanf_s("%d", &size);
	int list[100];
	for (int i = 0; i < size; i++)
		scanf_s("%d", &list[i]);
	
	mergeSort(list, 0, size-1);
	for (int i = 0; i < size; i++)
		printf("%d ", list[i]);
}