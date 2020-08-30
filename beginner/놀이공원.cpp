
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n, m;
int fp, rp;
int map[101][101];
int x[101], y[101], len[101];

void enQueue(int _x, int _y, int _z) {
	x[rp] = _x;
	y[rp] = _y;
	len[rp] = _z;
	rp++;
}

void deQueue() {
	fp++;
}

bool possibleTomove(int a, int b) {
	if (a < b) {
		if ((b - a) <= 1)
			return true;
	}
	if (a == 1 && b==1) 
		return true;
	return false;
}

void bfs() {
	
	enQueue(0,0,1);
	while (fp < rp && (x[fp] != n || y[fp] != m) ) {

		if ((x[fp] -1) > 0 && possibleTomove(map[x[fp] - 1][y[fp]],map[x[fp]][y[fp]])) {
			enQueue(x[fp] -1, y[fp], len[fp] + 1);
		}
			
		if ((x[fp] + 1) < n && possibleTomove(map[x[fp] + 1][y[fp]], map[x[fp]][y[fp]])) {
			enQueue(x[fp] + 1, y[fp], len[fp] + 1);
		}
				
		if ((y[fp] -1)> 0 && possibleTomove(map[x[fp]][y[fp]-1], map[x[fp]][y[fp]])) {
			enQueue(x[fp], y[fp]-1, len[fp] + 1);
		}
		
		if ((y[fp]+1) < m && possibleTomove(map[x[fp]][y[fp]+1], map[x[fp]][y[fp]])) {
			enQueue(x[fp], y[fp]+1, len[fp] + 1);
		}

		map[x[fp]][y[fp]] = 100;
		deQueue();
	}	
	printf("\n%d\n", len[fp-1]);
}

int main(void) {
	clock_t start, end;
	double result;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}	
	}
	
	start = clock();
	bfs();
	end = clock();
	result = (double)(end - start);
	printf("%f\n", result / CLOCKS_PER_SEC);

	return 0;
}