#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct people {
	char name[20];
	int age;
	double height;

}Person;

typedef struct stack {
	Person p;
	struct stack* link;
}Stack;

Stack* geNode() {
	Stack* tmp = (Stack*)malloc(sizeof(Stack));
	tmp->link = NULL;

	return tmp;
}

void push(Stack** top, Person person) {
	Stack* tmp = *top;

	*top = getNode();
	(*top)->p = person;
	(*top)->link = tmp;
}

void printStack(Stack* top) {
	while (top != NULL) {
		printf("이름 : %s(%d세,%.1lfcm)\n",
			top->p.name,top->p.age,top->p.height);

		top = top->link;
	}
	printf("\n");
}

Person pop(Stack** top) {
	if (*top == NULL) {
		printf("Stack is Empty!!\n");
		return;
	}

	Stack* tmp = *top;
	Person rep = (*top)->p;

	*top = (*top)->link;
	free(tmp);

	return rep;
}

void clear(Stack** top) {
	while (*top != NULL) {
		pop(top);
	}
}

int main() {
	Stack* top = NULL;

	Person p1 = { "홍길동",22,176.3 };
	Person p2 = { "김길동",32,186.1 };
	Person p3 = { "이길동",12,166.7 };

	//printf("p1 이름 : %s\n",p1.name);

	//Person p4 = p1;
	//printf("p4 이름 : %s\n", p4.name);

	push(&top, p1);
	push(&top, p2);
	push(&top, p3);
	
	printStack(top);
	Person result = pop(&top);

	printf("꺼낸값) 이름 : %s(%d세, %.1lfcm)\n",
		result.name, result.age, result.height);

	clear(&top);
}