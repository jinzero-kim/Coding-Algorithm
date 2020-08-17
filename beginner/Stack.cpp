
#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK (1 << 10)

int stack[MAXSTACK];
int sp = -1;

int IsEmpty() {
	if (sp < 0)
		return true;
	else
		return false;
}

int IsFull() {
	if (sp >= MAXSTACK - 1)
		return true;
	else
		return false;
}

void push(int value) {
	if (IsFull())
		printf("stack is full\n");
	else
		stack[++sp] = value;
}

int pop() {
	if (IsEmpty()) {
		printf("stack is empty\n");
		exit(-1);
	}
	else {
		return stack[sp--];
	}
}

int main(void) {

	push(3);
	push(5);
	push(12);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());

	return 0;
}




