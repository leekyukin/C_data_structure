#include <stdio.h>
#define swap(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
int tmp; 

void sort(int list[], int size) {
	int k;
	for (int i = 0; i < size; i++) {
		k = i;
		for (int j = i + 1; j < size; j++) {
			if (list[k] > list[j])
				k = j;
		}
		swap(list[k], list[i], tmp);
	}
}


int main(void) {
	int list[8] = { 5,4,7,6,5,5,7,4 };
	sort(list, 8);
	for (int i = 0; i < 8; i++)
		printf("%d ", list[i]);
}
