#include <stdio.h>

int arr[10];
int main(void) {
	int list2[100];
	char list[100];
	scanf("%s", list);
	for (int i = 0; list[i] != '\0'; i++) {
		list2[i] = (list[i] - 48);
		arr[list2[i]]++;
	}
		
	int max = 0;
	for (int i = 0; i <= 10; i++) {
		if (arr[max] <= arr[i])
			max = i;
	}

	printf("%d", max);
}