
#include <stdio.h>
#include <stdlib.h>

int h,w;
int fp = 0; // front pointer
int rp = 0; // rear pointer
char map[40][40];
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

	EnQueue(_x, _y, 0);

	while (fp < rp && (y[fp] != h - 1)) {
		map[y[fp]][x[fp]] = 'x';

		if (y[fp] > 0 && map[y[fp] - 1][x[fp]] == '.') {
			EnQueue(x[fp], y[fp] - 1, len[fp] + 1);
		}

		if (y[fp] < h - 1 && map[y[fp] + 1][x[fp]] == '.') {
			EnQueue(x[fp], y[fp] + 1, len[fp] + 1);
		}

		if (x[fp] > 0 && map[y[fp]][x[fp] - 1] == '.') {
			EnQueue(x[fp] - 1, y[fp], len[fp] + 1);
		}

		if (x[fp] < w - 1 && map[y[fp]][x[fp] + 1] == '.') {
			EnQueue(x[fp] + 1, y[fp], len[fp] + 1);
		}

		DeQueue();
	}
	printf("the Shortest path length: %d\n", len[fp]);
}

int main(void) {
	scanf("%d%d", &h, &w);
	for (int i = 0; i < h; i++) {
		scanf("%s", map[i]);
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 'G')
				map[i][j] = '.';
		}
	}
	BFS(0, 1);

	return 0;
}