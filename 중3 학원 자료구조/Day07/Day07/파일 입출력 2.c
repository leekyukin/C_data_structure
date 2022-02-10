#include<Stdio.h>

int main() {
	FILE* fp = fopen("test.txt", "r");

	char word[20];
	char word2[20];

	fscanf(fp, "%s %s", word, word2);

	printf("word = %s\n", word);
	printf("word = %s\n", word);
}