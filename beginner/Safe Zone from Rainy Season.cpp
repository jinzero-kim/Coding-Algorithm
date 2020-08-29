
#include <stdio.h>
#include <stdlib.h>

int n;
int maxH; //max height among each point 
int map[101][101];
int temp[101][101];
int a[101],t; //safe zone count

int dx[4] = { 0,0,-1,1 };
int dy[4] = {-1,1,0,0 };


void dfs(int i, int j, int k) {

	if (temp[i][j] <= k) return;

	temp[i][j] = k;
	a[t]++;

	for (int m = 0; m < 4; m++) {
		dfs(i + dx[m], j + dy[m], k);
	}
}

int main(void) {

	scanf("%d", &n);
		
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			temp[i][j] = map[i][j];
			if (maxH < map[i][j]) {
				maxH = map[i][j];
			}
		}
	}
	
	int maxS=0; //safe zone max
	for (int k = 1; k <= maxH; k++) {
		t = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (temp[i][j] > k) {
					dfs(i, j, k);
					t++;
				}
				temp[i][j] = map[i][j];
				if (maxS < t)
					maxS = t;
			}
		}
	}

	printf("\n");
	printf("%d", maxS);

	return 0;
}