#include<stdio.h>

// ����ü �����Ǵ� ����� �ٷ� ���� ����

typedef struct po2 {
	int x, y;	// int x;
				// int y;
}Po2;

void printPoint(Po2 p) {
	printf("��ǥ : (%d, %d)\n", p.x, p.y);
}

Po2 addPoint(Po2 p1, Po2 p2) {
	Po2 tmp;

	tmp.x = p1.x + p2.x;
	tmp.y = p1.y + p2.y;

	return tmp;
}

void swap(Po2* p1, Po2* p2) {
	Po2 tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int main() {
	Po2 p1 = { 1,2 };
	Po2 p2 = { 4,9 };
	Po2 p3;

	p3 = p1;	// ��� ������ 1:1�� ���簡 �ȴ�
	
	printPoint(p1);		// ��ǥ : (1, 2)
	printPoint(p2);
	printPoint(p3);

	p3 = addPoint(p1, p2);		// ������ �� ��ǥ�� ���ؼ� ��ȯ�ϴ� �Լ�
	printPoint(p3);		// ��ǥ : (5, 11)

	// �߰� ����) p1�� p2�� ��ǥ�� ���� ��ȯ�ϴ� swap ����
	printf("\n");
	swap(&p1, &p2);

	printPoint(p1);
	printPoint(p2);
}