
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int h=7, w=7;
int map[h][w];
int dx[12] = {0,0,1,2,0,1,0,1,0,-1,1,1};
int dy[12] = {1,2,0,0,1,1,1,0,1,1,0,1 };
int match[5];

bool checkRange(int c_x, int c_y) {
	if ((c_x >= 0 && c_x < h) && (c_y >= 0 && c_y < w))
		return true;
	else
		return false;
}

void dfs(int _x, int _y) {
	int color;
	color = map[_x][_y];

	for (int r = 0; r < 12; r=r+2) {
		if ((map[_x + dx[r]][_y + dy[r]] == color) && checkRange(_x + dx[r], _y + dy[r])) {
			if ((map[_x + dx[r+1]][_y + dy[r+1]] == color) && checkRange(_x + dx[r + 1], _y + dy[r + 1])) {
				match[color]++;
			}
		}
	}
}

void solve() {
	for (int x = 0; x < h; x++) {
		for (int y = 0; y < w; y++) {
			dfs(x,y);
		}
	}

	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += match[i];
	}
	printf("\n%d\n", sum);
}

int main(void) {
	clock_t start, end;
	double result;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	start = clock();

	solve();

	printf("\n");
	end = clock();
	result = (double)(end - start);
	printf("%f\n", result / CLOCKS_PER_SEC);

	return 0;
}