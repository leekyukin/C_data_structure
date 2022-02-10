#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10

void printScore(int s[]) {
	for (int i = 0; i < MAX; i++) {
		printf("%d ", s[i]);
	}
	printf("\n");
}

int main() {
	int num;
	int score[MAX];
	int max = 0, min = 100;

	srand(time(NULL));

	for (int i = 0; i < MAX; i++) {
		score[i] = rand() % 101;	// 학생점수를 랜덤으로 작성

		if (max < score[i]) max = score[i];
		if (min > score[i]) min = score[i];

	}
	
	printf("정렬전 : ");
	printScore(score);

	printf("1등 : %d\n", max);
	printf("꼴등 : %d\n", min);
	
	// 학생 점수를 낮은 순에서 부터 출력 후, 1등과 꼴등을 출력
	for (int i = 0; i < MAX - 1; i++) {
		for (int j = i + 1; j < MAX; j++) {
			if (score[i] > score[j]) {
				int tmp = score[i];
				score[i] = score[j];
				score[j] = tmp;
			}
		}
	}

	printf("정렬후 : ");
	printScore(score);

	printf("1등 : %d\n", score[MAX - 1]);
	printf("꼴등 : %d\n", score[0]);
}