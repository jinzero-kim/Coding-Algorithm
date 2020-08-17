
#include <stdio.h>
#include <stdlib.h>

#define MAXQ (1 << 10)
#define MOD (MAXQ -1)

int queue[MAXQ];
int fp = 0;
int rp = 0;

int IsEmpty() {
	if (fp == rp)
		return true;
	else
		return false;
}

void EnQueue(int value) {
	queue[rp] = value;
	rp = (rp+1) & MOD;	
}

int DeQueue() {
	int value;
	if (!IsEmpty()) {
		value = queue[fp];
		fp = (fp + 1) & MOD;
		return value;
	}
	else {
		printf("Queue is empty\n");
		exit(-1);
	}
}

int main(void) {
	
	EnQueue(3);
	EnQueue(73);
	EnQueue(12);
	EnQueue(23);
	EnQueue(90);

	printf("%d\n", DeQueue());
	printf("%d\n", DeQueue());
	printf("%d\n", DeQueue());
	printf("%d\n", DeQueue());
	printf("%d\n", DeQueue());
	printf("%d\n", DeQueue());

	return 0;
}