#include<stdio.h>
#include<stdlib.h>	// system() �Լ��� ������ �� ���̴�
#include<Windows.h>

int main() {
	int menu;

	do {
		printf("=========== �޴� ===========\n");
		printf("\t1. �޸���\n");
		printf("\t2. �׸���\n");
		printf("\t3. ����\n");
		printf("\t4. �۾�������\n");
		printf("\t5. ������\n");
		printf("\t0. ���α׷� ����\n");
		printf("\t>>> ");
		scanf_s("%d", &menu);

		switch (menu) {
		case 1:
			system("notepad");
			break;
		case 2:
			system("mspaint");
			break;
		case 3:
			system("calc");
			break;
		case 4:
			system("taskmgr");
			break;
		case 5:
			system("control");
			break;
		case 0:
			printf("���α׷� ����!!\n");
			break;;
		default:
			printf("�߸��� �޴��Դϴ�!!!\n");
		}

		system("pause");
		system("cls");
	} while (menu != 0);

	for (int i = 5; i >= 1; i--) {
		printf("%d\n", i);
		Sleep(1000);
	}

	printf("���ᰡ �Ϸ�Ǿ����ϴ�~~\n");
}