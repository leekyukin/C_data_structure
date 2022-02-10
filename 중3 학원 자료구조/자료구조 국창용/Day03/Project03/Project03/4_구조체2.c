#include<stdio.h>
#include<string.h>

// ���� : �����͸� �����ϴ� ����, ���� ����
// �迭 : ���� �ڷ������� �޸𸮻� ���ӵ� ����
// ����ü : �ٸ� ���� �ڷ����� ������� ����

struct person {
	char name[10];	// �̸�
	int age;		// ����
	double height;	// Ű
};

typedef struct person Person;

void printPerson(Person p) {
	printf("%s, %d, %.1lf\n", p.name, p.age, p.height);
}

int main() {
	struct person p1 = { "ȫ�浿", 25, 176.5 };

//	printf("p1 = %s, %d, %lf\n", p1.name, p1.age, p1.height);
	printPerson(p1);

	Person p2 = { "��浿", 15, 167.2 };
	printPerson(p2);

	Person p3;

//	p3.name = "��浿";	// �迭�� ���Կ������� ������ ���� �Ұ���

	strcpy(p3.name, "��浿");
	p3.age = 21;
	p3.height = 181.2;

	printPerson(p3);


	// �� ���ڿ� �Լ�
	// strlen("���ڿ�") : ���ڿ� ������ �����ش� (NULL���� ����)
	// strcpy("���ڿ�1", "���ڿ�2") : ���ڿ�2�� ���ڿ�1�� ����
	// strcmp("���ڿ�1", "���ڿ�2") : ���ڿ�1�� ���ڿ�2�� �������� ��
	//								������ 0�� ��ȯ, ���ڿ�1�� ũ�� 1�� ��ȯ, ���ڿ�1�� ������ -1�� ��ȯ
}