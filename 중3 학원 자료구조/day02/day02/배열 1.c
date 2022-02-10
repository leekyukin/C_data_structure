#include <stdio.h>



int main() {

	int arr[5] = { 10,20,30,40,50 };

	printf("arr = %p\n", arr);
	printf("0¹øÂ°  : %d\n", arr[0]);

	printf("arr = ");
	for (int i = 0; i < 5; i++) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}