#include <stdio.h>

int result, key, count;

int search(int list[], int start, int end) {

	int mid;
	if (start <= end) {
		count++;
		mid = (start + end) / 2;
		if (list[mid] == key) return count;
		else if (list[mid] > key) return search(list, start, mid - 1);
		else if (list[mid] < key) return search(list, mid + 1, end);
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