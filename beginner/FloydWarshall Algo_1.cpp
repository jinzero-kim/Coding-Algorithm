
#include <stdio.h>

const int n = 5;
int INF = 1000000000;

int ori_d[n][n] = {
	{ 0,8,5,INF,INF },
	{ INF,0,INF,17,9 },
	{ 6,INF,0,5,10 },
	{ INF,17,INF,0,4 },
	{ INF,INF,11,6,0 },
};

void floydWarshall() {
	int new_d[n][n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			new_d[i][j] = ori_d[i][j];
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (new_d[i][k] + new_d[k][j] < new_d[i][j]) {
					new_d[i][j] = new_d[i][k] + new_d[k][j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", new_d[i][j]);
		}
		printf("\n");
	}

}

int main(void) {

	floydWarshall();

	return 0;
}