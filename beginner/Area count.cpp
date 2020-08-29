
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int m,n,k;
int map[101][101];
int a[101],t;

int dx[4] = { 0,0,-1,1 };
int dy[4] = {-1,1,0,0 };

void dfs(int i, int j) {	
	if (i < 0 || j < 0 || i>m - 1 || j>n - 1) return;
	if (map[i][j] != 0) return;
	
	map[i][j] = 1;
	a[t]++;

	for (int m = 0; m < 4; m++) {
		dfs(i + dx[m], j + dy[m]);
	}
}

int main(void) {
	clock_t start, end;
	double result;

	start = clock();
	scanf("%d %d %d", &m, &n, &k);
		
	int x1,y1,x2,y2;
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) {
				map[x][y] = 1;
			}
		}
	}
		
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				dfs(i, j);
				t++;
			}
		}
	}

	printf("%d\n", t);

	int temp=0;
	for (int i = 0; i < t-1; i++) {
		for(int j=0;j< t-1-i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	
	for (int i = 0; i < t; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	end = clock();
	result = (double)(end - start);
	printf("%f", result/CLOCKS_PER_SEC);
	return 0;
}
