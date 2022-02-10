#include <stdio.h>
#define swap(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

void selectionSort(int list[], int size) {

	int key,tmp;
	for (int i = 0; i < size; i++) {
		key = i;
		for (int j = i+1; j < size; j++) {
			if (list[key] > list[j])
				key = j;
		}
		swap(list[key], list[i], tmp);
	}
}

int main(void) {

	int list[10] = { 2,9,4,5,37,3,4,1,3,7 };
	selectionSort(list, 10);
	for (int i = 0; i < 10; i++)
		printf("%d ", list[i]);

}