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

	printf("swap ��) n2 = %d , n2 = %d\n", n1, n2);
	swap(n1, n2);
	printf("swap �� ) n1 = %d, n2 = %d\n\n", n1, n2);

	printf("swap ��) n2 = %d , n2 = %d\n", n1, n2);
	pswap(&n1, &n2);     // �ּҸ� �����ϸ�, �ش� �Լ����� ã�ƿͼ� ���� ���� �� �� �ִ�
	printf("swap �� ) n1 = %d, n2 = %d\n", n1, n2);
	
	// �Լ��� ������ ȣ��� ���� �ܰ�(*)�� �����ʴ´�
	// �Լ��� �ּҷ� ȣ��� ���� �ܰ�(*)�� �þ��
	// ex)
	// �Լ� ȣ���  int�� ���� ����           => �Ű������� int
	// �Լ� ȣ��� int�� �ּ�(&)�� ����   =>�Ű������� int*

}