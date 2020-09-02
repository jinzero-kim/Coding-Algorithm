
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int stack[201];
int sp;

bool isEmpty() {
	if (sp >= 0)
		return false;
	else
		return true;
}

void enqueue(int value) {
	stack[sp++] = value;
}

int dequeue() {
	if (!isEmpty()) {
		return stack[--sp];
	}
	else {
		exit(-1);
	}
}

int main(void) {
	clock_t start, end;
	double result;
	char arr[201];

	gets_s(arr, sizeof(arr));

	start = clock();
	for (int i = 0; arr[i] != '\0'; i++) {
		if (arr[i] >= 48 && arr[i] <= 57) {
			enqueue(arr[i] - 48);
		}
		else {
			int temp1, temp2;
			if (arr[i] == '+') {
				temp2 = dequeue();
				temp1 = dequeue();
				enqueue(temp1 + temp2);
			}
			else if (arr[i] == '-') {
				temp2 = dequeue();
				temp1 = dequeue();
				enqueue(temp1 - temp2);
			}
			else if (arr[i] == '*') {
				temp2 = dequeue();
				temp1 = dequeue();
				enqueue(temp1*temp2);
			}
			else if (arr[i] == '/') {
				temp2 = dequeue();
				temp1 = dequeue();
				enqueue(temp1 / temp2);
			}
		}
	}
	printf("\n%d\n", dequeue());

	printf("\n");
	end = clock();
	result = (double)(end - start);
	printf("%f\n", result / CLOCKS_PER_SEC);

	return 0;
}