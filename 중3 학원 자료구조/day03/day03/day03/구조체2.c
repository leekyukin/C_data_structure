#include<stdio.h>
#include<string.h>

// ���� : �����͸� �����ϴ� ����, ���� ����
// �迭 : ���� �ڷ������� �޸𸮻� ���ӵ� ����
// ����ü : �ٸ� ���� �ڷ����� ������� ����

struct person {
	char name[10];   // �̸�
	int age;				  // ����
	double height;  // Ű
};

void printPerson(struct person p) {
	printf("%s,%d,%1.lf\n", p.name, p.age, p.height);
}

typedef struct person Person;

int main() {
	struct person p1 = { "ȫ�浿",25,175.5 };

	// printf("p1 = %s,%d,%lf\n", p1.name, p1.age, p1.height);
	printPerson(p1);

	Person p2 = { "��浿",15,167.2 };
	printPerson(p2);

	Person p3;
	p3.age = 21;

	printPerson(p3);

}