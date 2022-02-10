#include <stdio.h>

int main(void) {
	// if : 조건이 참이면 실행

	/*int age;

	printf("나이 입력 : ");
	scanf_s("%d", &age);

	if (age >= 20) {			// if문 : 참인 경우만 실행
		printf("성인");
	}

	else if (age >=17){			// esle if문 : 위의 조건이 거짓이면 검사하는 구문
		printf("고등학생");		// 참이면 실행,거짓이면 다음 구문으로
	}

	else if (age >= 14) {
		printf("중학생");
	}

	else {						// else문 : 준비된 조건이 모두 거짓일때 마지막에 실행
		printf("초등학생 ");	// else문은 필요없다면 작성하지 않기도 한다.
	}

	printf("입니다~\n");*/


	int n1, n2, n3; printf("정수 세개 입력 : "); scanf_s("%d%d%d", &n1, &n2, &n3);
	int max, min;

	max = n1;
	min = n1;

	//최대값
	if (max < n2) {
		max = n2;
	}
	if (max < n3) {
		max = n3;
	}

	// 최소값
	if (min > n2) {
		min = n2;
	}
	if (min > n3) {
		min = n3;
	}
	printf("최대값 : %d\n", max);
	printf("최소값 : %d\n", min);






	/*int a, b, c; printf("국어,영어,수학 점수 입력 : ");
	scanf("%d%d%d", &a, &b, &c);
	double sum;
	sum = (a + b + c) / 3;

	if (sum >= 90)
		printf("A");

	else if (sum >= 80)
		printf("B");

	else if (sum >= 70)
		printf("C");

	else if (sum >= 70)
		printf("D");

	else printf("F");
	return 0;*/
}