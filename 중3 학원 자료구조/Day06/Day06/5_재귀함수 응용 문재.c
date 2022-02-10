#include<stdio.h>

void HanoiTowerMove(int n, char src, char sub, char des) {

	if (n == 1) {
		printf("원반%d : %c ==> %c\n",n, src, des);
		return;
	}
	HanoiTowerMove(n - 1, src, des, sub);       // 1번 재귀 : 보조 기둥과 목적지 기둥을 변경
	printf("원반%d : %c ==> %c\n", n, src, des);
	HanoiTowerMove(n - 1, src, des, sub);     // 2번 재귀  : 보조 기둥과 출발 기둥을 변경                                                                                                                                                                                                                                                               
}


int mian(){
	
	HanoiTowerMove(2, 'A', 'B', 'C');
					//( 원반 개수, 출발기둥, 보조기둥, 목적지기둥)
	}