
#include <stdio.h>
#include <stdlib.h>

int n;
int fp = 0; // front pointer
int rp = 0; // rear pointer
int map[10][10];
int x[100], y[100], len[100];

int IsEmpty() {
	if (fp == rp)
		return true;
	else
		return false;
}

void EnQueue(int _x, int _y, int _len) {
	x[rp] = _x;
	y[rp] = _y;
	len[rp] = _len;
	rp++;
}

void DeQueue() {
	if (!IsEmpty()) {
		fp++;
	}
	else {
		printf("Queue is empty\n");
		exit(-1);
	}
}

void BFS(int _x, int _y) {

	EnQueue(_x, _y, 1);
	
	while (fp < rp && (x[fp] != n - 1 || y[fp] != n - 1)) {
		map[y[fp]][x[fp]] = 0;
		
		if (y[fp] > 0 && map[y[fp] - 1][x[fp]] == 1) {
			EnQueue(x[fp], y[fp] - 1, len[fp] + 1);
		}

		if (y[fp] < n - 1 && map[y[fp] + 1][x[fp]] == 1) {
			EnQueue(x[fp], y[fp] + 1, len[fp] + 1);
		}

		if (x[fp] > 0 && map[y[fp]][x[fp] - 1] == 1) {
			EnQueue(x[fp] - 1, y[fp], len[fp] + 1);
		}

		if (x[fp] < n - 1 && map[y[fp]][x[fp] + 1] == 1) {
			EnQueue(x[fp] + 1, y[fp], len[fp] + 1);
		}

		DeQueue();
	}
	printf("the Shortest path length: %d\n", len[fp]);
}

int main(void) {
	int i, j;
	
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &map[i][j]);
	
	BFS(0, 0);

	return 0;
}