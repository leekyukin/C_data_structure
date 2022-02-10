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

	printf("학생 목록)\n");

	while (head != NULL) {
		printf("%s  ", head->s.name);
		head = head->link;
		count++;
	}
	printf("\n총 학생 수 : %d명\n\n", count);
}

void search(List* head, char* find) {
	if (head == NULL) {
		printf("해당 학생은 존재하지 않음!!\n\n");
		return;
	}

	if (!strcmp(head->s.name, find)) {
		printf("학생 데이터 발견!!!)\n\n");

		printf("이름 : %s\n", head->s.name);
		printf("국어 : %d\n", head->s.kor);
		printf("영어 : %d\n", head->s.eng);
		printf("수학 : %d\n\n", head->s.mat);

		printf("합계 : %d\n", head->s.sum);
		printf("평균 : %.2lf\n\n", head->s.avg);

		return;
	}

	search(head->link, find);
}

void del(List** head, char* find) {
	if (*head == NULL) {
		printf("%s 학생은 존재하지 않음!!!\n\n", find);
		return;
	}

	if (!strcmp((*head)->s.name, find)) {
		List* tmp = *head;
		*head = (*head)->link;
		free(tmp);

		printf("%s 학생 데이터 삭제 완료!!\n", find);

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
		Student s = { "무명",-1,-1,-1,-1,-1 };

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
		printf("============= 메뉴 =============\n");
		printf("\t1. 학생 추가\n");
		printf("\t2. 학생 목록(이름만)\n");
		printf("\t3. 학생 검색\n");
		printf("\t4. 학생 데이터 삭제\n");
		printf("\t5. 저장\n");
		printf("\t6. 불러오기\n");
		printf("\t7. 종료\n");

		printf("\n\t입력 >>> ");
		scanf_s("%d", &menu);

		Student s;
		char name[15];

		switch (menu) {
		case 1:
			printf("이름 : ");
			scanf_s("%s", s.name, sizeof(s.name));

			printf("국 영 수 : ");
			scanf_s("%d %d %d", &s.kor, &s.eng, &s.mat);

			s.sum = s.kor + s.eng + s.mat;
			s.avg = s.sum / 3.0;

			add(&head, s);
			break;
		case 2:
			printList(head);
			break;
		case 3:
			printf("찾을 학생의 이름 : ");
			scanf_s("%s", name, sizeof(name));

			search(head, name);
			break;
		case 4:
			printf("삭제할 학생 데이터 : ");
			scanf_s("%s", name, sizeof(name));

			del(&head, name);
			break;
		case 5:
			save(head);
			printf("저장 완료!!!\n");
			break;
		case 6:
			load(&head);
			printf("불러오기 완료!!!\n");
			break;
		case 7:
			clear(&head);
			printf("프로그램 종료!!!\n\n");
			break;
		default:
			printf("없는 메뉴 번호!!\n");
		}

		system("pause");
		system("cls");


	} while (menu != 7);
}