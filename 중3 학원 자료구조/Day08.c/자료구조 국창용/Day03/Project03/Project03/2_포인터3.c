#include<stdio.h>

int main() {
	int num = 10;		// 4byte
	double db = 3.14;	// 8byte

	int* pnum = &num;	// 4byte
	double* pdb = &db;	// 4byte	=> 무조건 주소만 저장되기 때문

	printf("pnum - 1 = %p, pnum = %p, pnum + 1 = %p\n", pnum - 1, pnum, pnum + 1);
	// int* 의 주소 연산은 한칸을 4byte로 인식

	printf("pdb - 1 = %p, pdb = %p, pdb + 1 = %p\n", pdb - 1, pdb, pdb + 1);
	// double* 의 주소 연산은 한칸을 8byte로 인식
}