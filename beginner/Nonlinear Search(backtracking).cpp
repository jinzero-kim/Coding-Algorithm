
#include <stdio.h>

int map[50][50];
int a[500];
int n, t = 1;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void dfs(int y, int x) {
	if (map[y][x] == 0) 
		return;
	a[t]++;
	map[y][x] = 0;

	for (int i = 0; i < 4; i++) {
		dfs(y + dy[i], x + dx[i]);
	}
	return;
}

int main(void) {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1;j <= n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 1) {
				dfs(i, j);
				t++;
			}
		}
	}
	printf("%d\n", t - 1);

	int temp;
	for (int i = 1; i < t; i++) {
		if (a[i] < a[i + 1]) {
			temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;
		}
	}

	for (int i = 1; i < t; i++) {
		printf("%d\n", a[i]);
	}

	return 0;
}
