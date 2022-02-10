#include <stdio.h>
#define swap(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

void bubbleSort(int list[], int size) {
	int tmp;
	for (int i = size-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (list[j] > list[j + 1])
				swap(list[j], list[j + 1], tmp);
		}
	}
}


int main(void) {
	int list[10] = { 2,9,3,6,2,1,9,10,8,4 };
	bubbleSort(list, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", list[i]);
	}
}