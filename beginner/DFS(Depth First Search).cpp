
#include <stdio.h>

int n;
int m[50][50], visit[50];

void DFS(int v) {

	visit[v] = 1;

	for (int i = 1; i <= n; i++) {
		if (m[v][i] == 1 && !visit[i])
		{
			printf("move from%d to%d \n", v, i);
			DFS(i);
		}
	}
}

int main(void) {
	int start;
	int i, j;

	scanf("%d%d", &n, &start);

	while (1) {
		scanf("%d%d", &i, &j);
		if (i == -1 && j == -1) break;
		m[i][j] = m[j][i] = 1;
	}

	DFS(start);

	return 0;
}