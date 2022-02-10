#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct list {
	int data;
	struct list* link;
}List;

List* getNode() {
	List* newnode = (List*)malloc(sizeof(List));
	newnode->link = NULL;
	return newnode;
}

void add(List** head, int num) {
	if (*head == NULL) {
		*head = getNode();
		(*head)->data = num;

		return;
	}

	add(&(*head)->link, num);
}

void printList(List* head) {
	int count = 0;

	while (head != NULL) {
		printf("%d -> ", head->data);
		head = head->link;
		
		count++;
		
		if (count % 5 == 0) printf("\b\b\b  \n-> ");
	}
	printf("\b\b\b  \n");
}

void del(List** head, int num) {
	if (*head == NULL) {
		printf("\n%d(��)�� ���� ������!!!\n", num);
		return;
	}

	if ((*head)->data == num) {
		List* tmp = *head;
		*head = (*head)->link;
		free(tmp);

		printf("\n%d ������ ����!!\n", num);
		return;
	}

	del(&(*head)->link, num);
}

void modify(List** head, int src, int dst) {
	if (*head == NULL) {
		printf("\n%d(��)�� ���� ������!!!\n", src);
		return;
	}

	if ((*head)->data == src) {
		(*head)->data = dst;
		return;
	}

	modify(&(*head)->link, src, dst);
}

void insert(List** head, int src, int dst) {
	if (*head == NULL) {
		printf("\n%d(��)�� ���� ������!!!\n", src);
		return;
	}

	if ((*head)->data == src) {
		List* newnode = getNode();
		newnode->data = dst;

		newnode->link = (*head)->link;
		(*head)->link = newnode;

		return;
	}

	insert(&(*head)->link, src, dst);
}

void clear(List** head) {
	while (*head != NULL) {
		List* tmp = *head;
		*head = (*head)->link;
		free(tmp);
	}
}

void sort(List** head) {
	// ���� ���� ������ ����Ҳ���~

	List* tmp;
	int count = 0;

	while (1) {
		tmp = *head;	// �ݺ� ����۽� tmp�� �� ������
		count = 0;		// count�� �ٽ� 0���� �ʱ�ȭ

		while (tmp->link != NULL) {

			//	(�� ������ > �� ������)
			if (tmp->data > tmp->link->data) {
				int sw = tmp->data;
				tmp->data = tmp->link->data;
				tmp->link->data = sw;
				
				count++;
			}

			tmp = tmp->link;	// if�� ���� ���ο� �������
								// ���� �����ͷ� ����
		}

		if (count == 0)		break;
	}
}

int main() {
	List* head = NULL;
	int menu;

	do {
		printList(head);

		printf("������������������������������������������������\n");
		printf("��\t1. add \t       ��\n");
		printf("��\t2. insert      ��\n");
		printf("��\t3. modify      ��\n");
		printf("��\t4. delete      ��\n");
		printf("��\t5. random      ��\n");
		printf("��\t6. sort        ��\n");
		printf("������������������������������������������������\n");

		printf("\n�Է�(0 : ����) : ");
		scanf_s("%d", &menu);

		int num, dst;
		srand(time(NULL));	// ������ �پ��ϰ�

		switch (menu) {
		case 1:
			printf("�߰��� ������ : ");
			scanf_s("%d", &num);
			add(&head, num);
			break;
		case 2:
			printf("� ������ �ڿ�? ");
			scanf_s("%d", &num);
			
			printf("�߰��� ������ : ");
			scanf_s("%d", &dst);

			insert(&head, num, dst);
			break;
		case 3:
			printf("������ ������ : ");
			scanf_s("%d", &num);

			printf("� �����ͷ�? ");
			scanf_s("%d", &dst);

			modify(&head, num, dst);
			break;
		case 4:
			printf("������ ������ : ");
			scanf_s("%d", &num);
			del(&head, num);
			break;
		case 5:
			for (int i = 0; i < 10; i++) {
				num = rand() % 50 + 1;
				add(&head, num);
			}

			printf("10�� �������� ä��!!!\n");
			break;
		case 6:
			sort(&head);
			printf("���� �Ϸ�!!\n");
			break;
		case 0:
			clear(&head);
			printf("���α׷��� ���� �մϴ�~\n");
			break;
		default :
			printf("���� �޴� ��ȣ!!!\n");
		}

		system("pause");
		system("cls");

	} while (menu != 0);
}