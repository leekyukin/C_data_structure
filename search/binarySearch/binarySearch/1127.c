#include <stdio.h>
int list[13] = { 1,2,3,4,6,9,11,13,14,15,17,18,19 };
int result, count, key;

int search(int start, int end) {

	int middle;
	if (start <= end) {
		count++;
		middle = (start + end) / 2;
		if (key == list[middle]) return count;
		else if (key > list[middle]) return search(middle + 1, end);
		else if (key < list[middle]) return search(start, middle - 1);
	}
	return -1;
}


int main(void) {

	printf("key : ");
	scanf_s("%d", &key);
	result = search(0, 12);
	if (result == -1) printf("Å½»ö ½ÇÆĞ!");
	else printf("Å½»ö È½¼ö : %d", result);

}


