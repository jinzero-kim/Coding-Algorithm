
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n, m;
char map[101][101];
int s, t;
int possible_d, temp_d;
int roomChange_c;

int dfs(int _x, int _y) {
	int temp_d=0, max_d=0;

	for (int j = 1; j <= m; j++) {
		temp_d = 0;
		for (int i = _x; i <= _y; i++) {
			if (map[i][j] == 'O') {
				temp_d++;
			}
			else break;
		}
		if (temp_d > max_d) {
			max_d = temp_d;
		}
	}
	return max_d;
}

void solve(int _s, int _t) {		
	int req_d = _t - _s;
	int temp_d=0;

	while (_s <= _t) {		
		temp_d = dfs(_s, _t);
		if ((possible_d += temp_d) >= req_d) break;
		_s += temp_d;
		roomChange_c++;
	}	

	if (possible_d >= req_d) {
		printf("\n%d\n", roomChange_c);
	}
	else {
		printf("\n%d\n", -1);
	}
}

int main(void) {
	clock_t start, end;
	double result;

	scanf("%d%d", &n, &m);

	for (int i = 1; i < n + 1; i++) {
		scanf("%s", &map[i][1]);
	}
	scanf("%d%d", &s, &t);

	start = clock();

	solve(s, t);

	printf("\n");
	end = clock();
	result = (double)(end - start);
	printf("%f\n", result / CLOCKS_PER_SEC);

	return 0;
}