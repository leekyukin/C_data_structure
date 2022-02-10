#include<stdio.h>
#include<stdlib.h>

int main() {
	double* pdb1, * pdb2;

	pdb1 = (double*)malloc(8);
	pdb2 = (double*)malloc(sizeof(double));

	printf(" 두 실수 입력 : ");
	scanf_s("%lf%lf", pdb1, pdb2);

	pritnf("*pdb1 = %.2lf, *pdb2 = %.2lf\n", *pdb1, *pdb2);

	free(pdb1);
	free(pdb2);

}