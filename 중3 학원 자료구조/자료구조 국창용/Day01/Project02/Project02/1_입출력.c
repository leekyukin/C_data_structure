#include<stdio.h>

// stdio.h : standard input ouput, 표준 입출력 헤더

int main() {
	printf("표준 출력 구문 입니다~\n");

	char word[10];
	int num;
	double pi;

	printf("입력 구문 word : ");
	scanf_s("%s", word, sizeof(word));

	printf("word = %s\n\n", word);

	printf("입력 구문 num : ");
	scanf_s("%d", &num);

	printf("num = %d\n\n", num);

	printf("입력 구문 pi : ");
	scanf_s("%lf", &pi);

	printf("pi = %lf\n", pi);
}