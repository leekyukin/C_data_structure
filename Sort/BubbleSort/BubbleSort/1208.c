#include <stdio.h>
#define swap(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

void sort(int list[], int size) {
	int tmp;
	for (int i = size - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (list[j] > list[j + 1])
				swap(list[j], list[j + 1], tmp);
		}
	}

}

int main(void) {

	int list[8] = { 1,9,2,8,4,5,6,3 };

	sort(list, 8);
	for (int i = 0; i < 8; i++)
		printf("%d ", list[i]);
}