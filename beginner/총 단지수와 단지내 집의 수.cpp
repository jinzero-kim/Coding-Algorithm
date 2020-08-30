
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n;
int map[101][101];
int a[101], t;
int dx[4] = { 0,0,-1,1 }; //scan
int dy[4] = { -1,1,0,0 }; //scan

void dfs(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>n - 1) return;
	if (map[x][y] == 0 ) return;

	map[x][y] = 0;
	a[t]++;

	for (int r = 0; r < 4; r++) {
		dfs(x + dx[r], y + dy[r]);
	}
}

int main(void) {
	clock_t start, end;
	double result;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	start = clock();
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (map[x][y] == 1) {
				dfs(x,y);
				t++;
			}
		}
	}

	printf("%d\n", t);
	
	int temp;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t-1-i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < t; i++) {
		printf("%d\n", a[i]);
	}

	end = clock();
	result =(double)(end - start);
	printf("%f\n", result/CLOCKS_PER_SEC);

	return 0;
}