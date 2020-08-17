
#include <stdio.h>
#include <stdlib.h>

#define MAXQ 100
int fp = 0;
int rp = 0;
int n; // vertex max value
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
	int i;

	visit[v] = 1;
	printf("%d에서 시작\n", v);

	EnQueue(v);
	while (fp < rp) {
		v = DeQueue();
		//printf("%d\n", v);
		for (i = 1; i <= n; i++) {
			if (map[v][i] == 1 && !visit[i]) {
				visit[i] = 1;
				printf("%d에서 %d로 이동\n", v, i);
				EnQueue(i);
			}
		}
	}
}

int main(void) {
	int start;
	int v1, v2;

	scanf("%d%d", &n, &start);

	while (1) {
		scanf("%d%d", &v1, &v2);
		if (v1 == -1 && v2 == -1) 
			break;
		map[v1][v2] = map[v2][v1] = 1;
	}

	BFS(start);

	return 0;
}