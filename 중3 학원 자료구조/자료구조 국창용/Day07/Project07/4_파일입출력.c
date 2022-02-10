#include<stdio.h>

// 파일 출력 : 쓰기
// 파일 입력 : 읽기

// 기준이 프로그램이 기준이 된다
// 프로그램 -> 파일	:  프로그램에서 데이터가 나가면 '출력'
// 프로그램 <- 파일	:  프로그램으로 데이터가 들어오면 '입력'

int main() {
	// 파일 모드 : r(읽기), w(쓰기), a(추가)
	FILE* fp = fopen("test.txt", "w");

	fprintf(fp, "Hello World!!!\n");

	fclose(fp);		// 파일을 닫는 함수
}