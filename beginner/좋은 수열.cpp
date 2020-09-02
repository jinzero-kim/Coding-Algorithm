
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n;
int data[101];
bool check = false;

bool isGoodSequence(int _k , int m) {
	int mid = m / 2;

	data[m] = _k;

	for (int i = 1; i <= mid;i++) {
		int c = 0;
		for (int j = 0; j < i; j++) {
			if (data[m - j] == data[m - i - j]) c++;
		}
		if (c == i) return false;
	}
	return true;
}

void solve(int _n) {
	if (_n == n) {
		check = true;
		return;
	}

	for (int k = 1; k <= 3; k++) {
		if (check) break;
		if (isGoodSequence(k, _n+1)) {
			solve(_n+1);
		}
	}
}

int main(void) {
	clock_t start, end;
	double result;

	scanf("%d", &n);

	start = clock();

	solve(0);

	printf("\n");
	for (int i = 1; i <= n; i++) {
		printf("%d", data[i]);
	}

	printf("\n");
	end = clock();
	result = (double)(end - start);
	printf("%f\n", result / CLOCKS_PER_SEC);

	return 0;
}
