
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define black 1
#define white 2
#define WIN true
#define LOSE false

const int n = 19, m = 19;
const int black_array = 3, white_array = 3;
int map[101][101];
int dx[8] = { 1,0,1 }; //scan
int dy[8] = { 0,1,1 }; //scan
int omok; //consecutive stone count
int win[3]; //result

void recur(int _x, int _y, int _bw, int _r) {
	if (_x < 0 || _y < 0 || _x>19 || _y>19) return;
	if (map[_x][_y] != _bw) return;

	omok++;
	if (map[_x + dx[_r]][_y + dy[_r]] == _bw) {
		recur(_x + dx[_r], _y + dy[_r], _bw, _r);
	}
}

bool dfs(int x, int y, int bw) {
	int startX, startY;

	startX = x;
	startY = y;
	for (int r = 0; r < 3; r++) {
		omok = 0;
		if (map[x + dx[r]][y + dy[r]] == bw) {
			omok++;
			recur(x + dx[r], y + dy[r], bw, r);
			if (omok == 5) {
				win[0] = ((bw == white) ? 2 : 1);
				win[1] = startX + 1;
				win[2] = startY + 1;
				return WIN;
			}
		}
	}
	return LOSE;
}

int main(void) {
	clock_t start, end;
	double result;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	start = clock();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == black) {
				if (dfs(i, j, black) == WIN) break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == white) {
				if (dfs(i, j, white) == WIN) break;
			}
		}
	}

	printf("\n%d\n", win[0]);
	for (int i = 1; i < 3; i++) {
		printf("%d ", win[i]);
	}

	printf("\n");
	end = clock();
	result = (double)(end - start);
	printf("%f\n", result / CLOCKS_PER_SEC);

	return 0;
}