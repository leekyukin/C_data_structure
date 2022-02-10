#include <stdio.h>
int count, result, key;
int search(int list[], int start, int end) {
	int middle;
	if (start <= end) {
		count++;
		middle = (start + end) / 2;

		if (list[middle] == key) return count;
		else if (list[middle] > key) return search(list, start, middle - 1);
		else if (list[middle] < key) return search(list, middle + 1, end);
	}
	return -1;
}

int main(void) {
	int list[8] = { 1,2,4,5,6,7,9,13 };
	printf("key : ");
	scanf_s("%d", &key);
	result = search(list, 0, 7);
	if (result == -1) printf("Å½»ö ½ÇÆĞ\n");
	else printf("Å½»ö ¼º°ø!!\nÅ½»öÈ½¼ö : %d\n", result);
	
	
}