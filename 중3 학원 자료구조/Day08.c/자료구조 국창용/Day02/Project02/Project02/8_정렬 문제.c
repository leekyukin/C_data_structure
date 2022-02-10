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
		score[i] = rand() % 101;	// �л������� �������� �ۼ�

		if (max < score[i]) max = score[i];
		if (min > score[i]) min = score[i];

	}
	
	printf("������ : ");
	printScore(score);

	printf("1�� : %d\n", max);
	printf("�õ� : %d\n", min);
	
	// �л� ������ ���� ������ ���� ��� ��, 1��� �õ��� ���
	for (int i = 0; i < MAX - 1; i++) {
		for (int j = i + 1; j < MAX; j++) {
			if (score[i] > score[j]) {
				int tmp = score[i];
				score[i] = score[j];
				score[j] = tmp;
			}
		}
	}

	printf("������ : ");
	printScore(score);

	printf("1�� : %d\n", score[MAX - 1]);
	printf("�õ� : %d\n", score[0]);
}