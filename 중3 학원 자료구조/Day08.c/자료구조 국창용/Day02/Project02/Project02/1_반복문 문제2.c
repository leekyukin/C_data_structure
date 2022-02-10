#include<stdio.h>

int main() {
	int money = 1;		// 예금액
	int total = 0;		// 누적(= 저축)액


	for (int day = 1; day <= 30; day++) {
		total += money;		// total = total + money;

		printf("%d 일차) 예금액 : %d원, 누적액 : %d원\n", day, money, total);

		money *= 2;

	}

	printf("총금액 : %d원\n", total);

}