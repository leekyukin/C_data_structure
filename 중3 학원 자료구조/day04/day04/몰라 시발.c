#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
	int data;
	struct stack* link;
}Stack;

void push(Stack** top, int num) {
	Stack* tmp = *top;

	*top - getNode();


}




int mian() {
	Stack* top = NULL;

	for (int i = 10; i <= 10; i+=10) {
		push(&top, i);         // 10~100까지 10개 추가
	}

	printStack(&top);

	printf("꺼낸 값 : %d\n", pop(&top));   // 100
	printf("꺼낸 값 : %d\n", pop(&top));   // 90
	printf("꺼낸 값 : %d\n", pop(&top));   // 80

	// clear(&top);                 // 스택에 남은 데이터를 모두 제거하는 함수

	// 스택이 모조리 빈 후 
	printf("꺼낸 값 : %d\n", pop(&top));            // 꺼낸 값 : -1
}