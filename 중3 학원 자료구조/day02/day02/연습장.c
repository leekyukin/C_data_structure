#include<stdio.h>
#include<stdlib.h>
#include<windows.h>


int main() {
	int menu;
	do {


		printf("=========메뉴=========\n");
		printf("\t1.메모장\n");
		printf("\t2.그림판\n");
		printf("\t3.계산기\n");
		printf("\t4.작업관리자\n");
		printf("\t5.제어판\n");
		printf("\t0.프로그램 종료\n");
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
			system("teskmgr");
			break;
		case 5:
			system("control");
		case 0:
			system("프로그램 종료!!\n");
			break;
		default:
			printf("잘못된 메뉴입니다!!!\n");
		}
		system("pause");
		system("cls");
	
	
	} while (menu != 0);

	for (int i =5;)
		









	return 0;
}