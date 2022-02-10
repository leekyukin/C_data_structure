#include <stdio.h>
int count, result, list[13] = { 1,2,3,6,8,9,10,12,13,14,16,18,100 }, key;
int search(int start, int end) {
	int middle;
	if (start <= end) {
		count++;
		middle = (start + end) / 2;
		
		if (list[middle] == key) return count;
		else if (list[middle] > key) return search(start, middle - 1);
		else if (list[middle] < key) return search(middle + 1, end);
	}
	return -1;
}

int main(void) {

	printf("key : ");
	scanf_s("%d", &key);
	result = search(0, 12);
	if (result == -1) printf("Å½»ö ½ÇÆĞ\n");
	else printf("Å½»ö ¼º°ø !! \nÅ½»öÈ½¼ö : %d\n", result);

}