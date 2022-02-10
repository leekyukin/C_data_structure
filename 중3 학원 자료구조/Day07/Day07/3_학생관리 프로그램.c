#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student {
	char name[15];
	int kor, eng, mat, sum;
	double avg;
}Student;

typedef struct list {
	Student s;
	struct list* link;
}List;

List* getNode() {
	List* newnode = (List*)malloc(sizeof(List));
	newnode->link = NULL;
	return newnode;
}

void add(List** head, Student s) {
	if (*head == NULL) {
		*head = getNode();
		(*head)->s = s;

		return;
	}

	add(&(*head)->link, s);
}

void printList(List* head) {
	int count = 0;

	printf("�л� ���)\n");

	while (head != NULL) {
		printf("%s  ", head->s.name);
		head = head->link;
		count++;
	}
	printf("\n�� �л� �� : %d��\n\n", count);
}

void search(List* head, char* find) {
	if (head == NULL) {
		printf("�ش� �л��� �������� ����!!\n\n");
		return;
	}

	if (!strcmp(head->s.name, find)) {
		printf("�л� ������ �߰�!!!)\n\n");

		printf("�̸� : %s\n", head->s.name);
		printf("���� : %d\n", head->s.kor);
		printf("���� : %d\n", head->s.eng);
		printf("���� : %d\n\n", head->s.mat);

		printf("�հ� : %d\n", head->s.sum);
		printf("��� : %.2lf\n\n", head->s.avg);

		return;
	}

	search(head->link, find);
}

void del(List** head, char* find) {
	if (*head == NULL) {
		printf("%s �л��� �������� ����!!!\n\n", find);
		return;
	}

	if (!strcmp((*head)->s.name, find)) {
		List* tmp = *head;
		*head = (*head)->link;
		free(tmp);

		printf("%s �л� ������ ���� �Ϸ�!!\n", find);

		return;
	}

	del(&(*head)->link, find);
}

void clear(List** head) {
	while (*head != NULL) {
		List* tmp = *head;
		*head = (*head)->link;
		free(tmp);
	}

}

void save(List* head) {
	FILE* fp = fopen("save.txt", "w");

	while (head != NULL) {
		fprintf(fp, "%s %d %d %d %d %.2lf\n",
			head->s.name, head->s.kor, head->s.eng,
			head->s.mat, head->s.sum, head->s.avg);

		head = head->link;
	}

	fclose(fp);
}

void load(List** head) {
	FILE* fp = fopen("save.txt", "r");

	while (!feof(fp)) {
		Student s = { "����",-1,-1,-1,-1,-1 };

		fscanf(fp, "%s %d %d %d %d %lf",
			s.name, &s.kor, &s.eng, &s.mat, &s.sum, &s.avg);

		if (s.kor != -1) {
			add(head, s);
		}
		
	}
}

int main() {
	List* head = NULL;
	int menu;

	do {
		printf("============= �޴� =============\n");
		printf("\t1. �л� �߰�\n");
		printf("\t2. �л� ���(�̸���)\n");
		printf("\t3. �л� �˻�\n");
		printf("\t4. �л� ������ ����\n");
		printf("\t5. ����\n");
		printf("\t6. �ҷ�����\n");
		printf("\t7. ����\n");

		printf("\n\t�Է� >>> ");
		scanf_s("%d", &menu);

		Student s;
		char name[15];

		switch (menu) {
		case 1:
			printf("�̸� : ");
			scanf_s("%s", s.name, sizeof(s.name));

			printf("�� �� �� : ");
			scanf_s("%d %d %d", &s.kor, &s.eng, &s.mat);

			s.sum = s.kor + s.eng + s.mat;
			s.avg = s.sum / 3.0;

			add(&head, s);
			break;
		case 2:
			printList(head);
			break;
		case 3:
			printf("ã�� �л��� �̸� : ");
			scanf_s("%s", name, sizeof(name));

			search(head, name);
			break;
		case 4:
			printf("������ �л� ������ : ");
			scanf_s("%s", name, sizeof(name));

			del(&head, name);
			break;
		case 5:
			save(head);
			printf("���� �Ϸ�!!!\n");
			break;
		case 6:
			load(&head);
			printf("�ҷ����� �Ϸ�!!!\n");
			break;
		case 7:
			clear(&head);
			printf("���α׷� ����!!!\n\n");
			break;
		default:
			printf("���� �޴� ��ȣ!!\n");
		}

		system("pause");
		system("cls");


	} while (menu != 7);
}