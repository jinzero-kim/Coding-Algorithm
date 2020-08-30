
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int w, h;
int a[101], t;
char map[101][101];
int dx[8] = { -1,1,0,0, -1,-1,1,1 }; //scan
int dy[8] = { 0,0,-1,1,-1,1,-1,1 }; //scan

void dfs(int x, int y) {
	if (x<0 || y<0 || x>h || y>w) return;
	if (map[x][y] == '.') return;

	map[x][y] = '.';
	a[t]++;
	for (int r = 0; r < 8; r++) {
		if (map[x + dx[r]][y + dy[r]] == 'L') {
			dfs(x + dx[r], y + dy[r]);
		}
	}
}

int main(void) {
	clock_t start, end;
	double result;

	scanf("%d %d", &w, &h);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf(" %c", &map[i][j]);
		}
	}
	
	start = clock();
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 'L') {
				dfs(i, j);
				t++;
			}
		}
	}

	printf("\n%d\n", t);

	end = clock();
	result = (double)(end - start);
	printf("%f\n", result / CLOCKS_PER_SEC);

	return 0;
}