#include<stdio.h>
#include<stdlib.h>

int main() {
	int menu;
	Stack* top = NULL;

	do {
		printf("<==�޴�==>\n");
		printf("1. push\n");
		printf("2. pop\n");
		printf("3. print\n");
		printf("4. exit\n");
		printf(">>> ");
		scanf_s("%d", &menu);

		switch (menu) {
		case 1:
			printf("�߰��� ������ : ");
			scanf_s("%d", &num);

			push(&top, num);
			break;
		case 2:
		case 3:
		case 4:
		default :
			printf("���� �޴��Դϴ�!!!\n");
		}

		system("pause");
		system("cls");

	} while (menu != 4);
}