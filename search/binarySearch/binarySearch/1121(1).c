#include <stdio.h>
int list[9] = { 1,2,3,4,6,7,8,9,11 };
int count, result, key;

int search(int start, int end) {

	int middle;

	if (start <= end) {
		middle = (start + end) / 2;
		count++;
		if (list[middle] == key) return count;
		else if (list[middle] > key) return search(start, middle - 1);
		else if (list[middle] < key) return search(middle + 1, end);
	}
	return -1;
}

int main(void) {
	
		printf("Å½»ö °ª ÀÔ·Â : ");
		scanf_s("%d", &key);
		int result = search(0, 8);
		if (result == -1) printf("Å½»ö ½ÇÆĞ!!");
		else printf("Å½»ö ¼º°ø!!\n Å½»ö È½¼ö : %d ", result);
}