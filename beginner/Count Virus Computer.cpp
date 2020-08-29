
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXQ 100
int fp = 0;
int rp = 0;
int m;
int n; // connected vertex count
int map[MAXQ][MAXQ], queue[MAXQ], visit[MAXQ];

int IsEmpty() {
	if (fp == rp)
		return true;
	else
		return false;
}

void EnQueue(int value) {
	queue[rp] = value;
	rp = (rp + 1) % MAXQ;
}

int DeQueue() {
	int value;
	if (!IsEmpty()) {
		value = queue[fp];
		fp = (fp + 1) % MAXQ;
		return value;
	}
	else {
		printf("Queue is empty\n");
		exit(-1);
	}
}

void BFS(int v) {

	visit[v] = 1;

	EnQueue(v);
	while (fp < rp) {
		v = DeQueue();
		for (int i = 1; i <= n; i++) {
			if (map[v][i] == 1 && !visit[i]) {
				visit[i] = 1;
				EnQueue(i);
			}
		}
	}
	printf("%d\n", fp-1);
}

int main(void) {
	clock_t start, end;
	double result;

	start = clock();
	scanf("%d %d", &m, &n);

	int x, y;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		map[x][y] = map[y][x] = 1;
	}

	BFS(1);

	printf("\n");
	end = clock();
	result = (double)(end - start);
	printf("%f", result / CLOCKS_PER_SEC);
	return 0;
}