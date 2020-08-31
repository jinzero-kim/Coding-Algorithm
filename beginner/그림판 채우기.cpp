
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int h = 11, w = 11;
char map[h][w];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void dfs(int _x, int _y) {
	if (_x < 0 || _y < 0 || _x>10 || _y>10) return;
	if (map[_x][_y] == '*') return;

	map[_x][_y] = '*';
	for (int r = 0; r < 4; r++) {
		if (map[_x + dx[r]][_y + dy[r]] == '_') {
			dfs(_x + dx[r], _y + dy[r]);
		}		
	}
}

void solve(int x, int y) {	
	map[x][y] = '*';
	for (int r = 0; r < 4; r++) {
		if (map[x + dx[r]][y + dy[r]] == '_') {
			dfs(x + dx[r], y + dy[r]);
		}
	}

	for (int i = 1; i < h; i++) {
		for (int j = 1; j < w; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	clock_t start, end;
	double result;

	for (int i = 1; i < h; i++) {
		for (int j = 1; j < w; j++) {
			scanf(" %c", &map[i][j]);
		}
	}

	int startX, startY;
	scanf("%d%d", &startX, &startY);
		
	start = clock();
	
	solve(startY+1,startX+1);

	printf("\n");
	end = clock();
	result = (double)(end - start);
	printf("%f\n", result / CLOCKS_PER_SEC);

	return 0;
}