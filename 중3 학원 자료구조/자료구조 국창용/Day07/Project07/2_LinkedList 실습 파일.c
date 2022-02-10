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
		printf("\n%d(은)는 없는 데이터!!!\n", num);
		return;
	}

	if ((*head)->data == num) {
		List* tmp = *head;
		*head = (*head)->link;
		free(tmp);

		printf("\n%d 데이터 제거!!\n", num);
		return;
	}

	del(&(*head)->link, num);
}

void modify(List** head, int src, int dst) {
	if (*head == NULL) {
		printf("\n%d(은)는 없는 데이터!!!\n", src);
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
		printf("\n%d(은)는 없는 데이터!!!\n", src);
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
	// 저는 버블 정렬을 사용할께요~

	List* tmp;
	int count = 0;

	while (1) {
		tmp = *head;	// 반복 재시작시 tmp를 맨 앞으로
		count = 0;		// count도 다시 0으로 초기화

		while (tmp->link != NULL) {

			//	(앞 데이터 > 뒷 데이터)
			if (tmp->data > tmp->link->data) {
				int sw = tmp->data;
				tmp->data = tmp->link->data;
				tmp->link->data = sw;
				
				count++;
			}

			tmp = tmp->link;	// if문 실행 여부에 관계없이
								// 다음 데이터로 진행
		}

		if (count == 0)		break;
	}
}

int main() {
	List* head = NULL;
	int menu;

	do {
		printList(head);

		printf("┌──────────────────────┐\n");
		printf("│\t1. add \t       │\n");
		printf("│\t2. insert      │\n");
		printf("│\t3. modify      │\n");
		printf("│\t4. delete      │\n");
		printf("│\t5. random      │\n");
		printf("│\t6. sort        │\n");
		printf("└──────────────────────┘\n");

		printf("\n입력(0 : 종료) : ");
		scanf_s("%d", &menu);

		int num, dst;
		srand(time(NULL));	// 랜덤을 다양하게

		switch (menu) {
		case 1:
			printf("추가할 데이터 : ");
			scanf_s("%d", &num);
			add(&head, num);
			break;
		case 2:
			printf("어떤 데이터 뒤에? ");
			scanf_s("%d", &num);
			
			printf("추가할 데이터 : ");
			scanf_s("%d", &dst);

			insert(&head, num, dst);
			break;
		case 3:
			printf("수정할 데이터 : ");
			scanf_s("%d", &num);

			printf("어떤 데이터로? ");
			scanf_s("%d", &dst);

			modify(&head, num, dst);
			break;
		case 4:
			printf("삭제할 데이터 : ");
			scanf_s("%d", &num);
			del(&head, num);
			break;
		case 5:
			for (int i = 0; i < 10; i++) {
				num = rand() % 50 + 1;
				add(&head, num);
			}

			printf("10개 랜덤으로 채움!!!\n");
			break;
		case 6:
			sort(&head);
			printf("정렬 완료!!\n");
			break;
		case 0:
			clear(&head);
			printf("프로그램을 종료 합니다~\n");
			break;
		default :
			printf("없는 메뉴 번호!!!\n");
		}

		system("pause");
		system("cls");

	} while (menu != 0);
}