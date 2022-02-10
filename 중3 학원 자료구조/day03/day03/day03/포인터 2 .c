#include<stdio.h>
void swap(int n1, int n2) {
	int tmp = n1;
	n1 = n2;
	n2 = tmp;
}													// pswap = &main
void pswap(int* n1, int* n2) { // n1 = &n1,          n2 = &n2;
	int tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

int main() {
	int n1 = 10,  n2 = 20;

	printf("swap 전) n2 = %d , n2 = %d\n", n1, n2);
	swap(n1, n2);
	printf("swap 후 ) n1 = %d, n2 = %d\n\n", n1, n2);

	printf("swap 전) n2 = %d , n2 = %d\n", n1, n2);
	pswap(&n1, &n2);     // 주소를 전달하면, 해당 함수에서 찾아와서 값을 변경 할 수 있다
	printf("swap 후 ) n1 = %d, n2 = %d\n", n1, n2);
	
	// 함수를 값으로 호출시 참조 단계(*)는 늘지않는다
	// 함수를 주소로 호출시 참조 단계(*)가 늘어난다
	// ex)
	// 함수 호출시  int의 값을 전달           => 매개변수는 int
	// 함수 호출시 int의 주소(&)를 전달   =>매개변수는 int*

}