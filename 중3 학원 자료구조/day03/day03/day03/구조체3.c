#include<stdio.h>

// ����ü �����Ǵ� ����� �ٷ� ���� ����

typedef struct po2 {
	int x, y;   // int x;
				 //  int y;
}Po2;

void printfPoint(Po2 p) {
	printf("��ǥ : (%d, %d)\n", p.x, p.y);
}
int main() {
	Po2 p1 = { 1,2 };
	Po2 p2 = { 4,9 };
	Po2 p3;

	p3 = p1;    // �ɹ� ������  1:1�� ���簡 �ȴ�

	printfPoint(p1);
	printfPoint(p2);
	printfPoint(p3);

	/*p3 = addPoint(p1, p2);  */    // ������ �� ��ǥ�� ���ؼ� ��ȯ�ϴ� �Լ�
	printPoint(p3);               // ��ǥ : (5,11)

}