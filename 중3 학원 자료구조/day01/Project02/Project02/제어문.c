#include <stdio.h>

int main(void) {
	// if : ������ ���̸� ����

	/*int age;

	printf("���� �Է� : ");
	scanf_s("%d", &age);

	if (age >= 20) {			// if�� : ���� ��츸 ����
		printf("����");
	}

	else if (age >=17){			// esle if�� : ���� ������ �����̸� �˻��ϴ� ����
		printf("����л�");		// ���̸� ����,�����̸� ���� ��������
	}

	else if (age >= 14) {
		printf("���л�");
	}

	else {						// else�� : �غ�� ������ ��� �����϶� �������� ����
		printf("�ʵ��л� ");	// else���� �ʿ���ٸ� �ۼ����� �ʱ⵵ �Ѵ�.
	}

	printf("�Դϴ�~\n");*/


	int n1, n2, n3; printf("���� ���� �Է� : "); scanf_s("%d%d%d", &n1, &n2, &n3);
	int max, min;

	max = n1;
	min = n1;

	//�ִ밪
	if (max < n2) {
		max = n2;
	}
	if (max < n3) {
		max = n3;
	}

	// �ּҰ�
	if (min > n2) {
		min = n2;
	}
	if (min > n3) {
		min = n3;
	}
	printf("�ִ밪 : %d\n", max);
	printf("�ּҰ� : %d\n", min);






	/*int a, b, c; printf("����,����,���� ���� �Է� : ");
	scanf("%d%d%d", &a, &b, &c);
	double sum;
	sum = (a + b + c) / 3;

	if (sum >= 90)
		printf("A");

	else if (sum >= 80)
		printf("B");

	else if (sum >= 70)
		printf("C");

	else if (sum >= 70)
		printf("D");

	else printf("F");
	return 0;*/
}