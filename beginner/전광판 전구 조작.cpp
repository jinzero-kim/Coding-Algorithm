
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n,m;
int map[101][101];
int temp[101][101];
int On[101], Off[101], On_t, Off_t;
int dx[4] = { 0,0,-1,1 }; //scan
int dy[4] = { -1,1,0,0 }; //scan

void dfs(int x, int y, int OnOff) {
	if (x<0 || y<0 || x>n - 1 || y >m - 1) return;
	if (temp[x][y] != OnOff) return;

	if (OnOff == 1) {
		On[On_t]++;
	}
	else {
		Off[Off_t]++;
	}

	temp[x][y] = (OnOff == 1) ? 0 : 1;

	for (int r = 0; r < 4; r++) {
		dfs(x + dx[r], y + dy[r], OnOff);
	}
}

int main(void) {
	clock_t start, end;
	double result;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			temp[i][j] = map[i][j];
		}
	}

	start = clock();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 1) {
				dfs(i,j,1);
				On_t++;	
			}
			temp[i][j] = map[i][j];	
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) {
				dfs(i, j, 0);
				Off_t++;
			}
		}
	}
	
	printf("\n%d %d\n", Off_t, On_t);

	end = clock();
	result = (double)(end - start);
	printf("%f\n", result / CLOCKS_PER_SEC);

	return 0;
}