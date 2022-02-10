#include <stdio.h>
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

	srand(time(NULL));

	for (int i = 0; i < MAX; i++) {
		score[i] = rand() % 101;
		
	}

	printf("Á¤·ÄÀü : ");
	printScore(score);

	for (int i = 0; i < MAX=1; i++) {
		for (int j = i + 1; j < MAX; j++) {
			if (score[i] > score[j]) {
				int tmp = 0;
				tmp = arr[i];
				score[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}


	return 0;
}