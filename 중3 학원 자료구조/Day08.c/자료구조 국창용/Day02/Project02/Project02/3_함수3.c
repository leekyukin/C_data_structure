#include<stdio.h>

// �Լ��� �ڷ��� : ��ȯ��, �Լ��� ���� ��� �������� �ڷ����� �ǹ�
int adder(int n1, int n2) {
	int result;

	result = n1 + n2;

	return result;	// return ��ȯ��;   �ش簪�� �Լ��� ȣ�� ��ġ�� �ǵ����ش�(= ��ȯ)
}


int main() {

	int sum;

	sum = adder(10, 7);						// ��ȯ���� ����
	printf("sum = %d\n", sum);

	printf("��� : %d\n", adder(20, 4));		// ��ȯ���� ���� ���

	// ��, ��ȯ���� �ִ� �Լ��� ���� �������� �ʰų� �ٷ� Ȱ������ ������ ������� ������ ����
	// ��ȯ���� �ִ� �Լ� : char, int, float, double ��
	// ��ȯ���� ���� �Լ� : void

	sum = adder(adder(10, 2), adder(20, 3));	// ��ȯ���� �ٸ� �Լ��� ���ް����� ��뵵 ����
	printf("sum = %d\n", sum);
}