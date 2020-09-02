
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int s;
int data[101];
int dp[101];

int isMax(int a, int b) {
	if (a < b) return b;
	else return a;
}

int recur(int n) {
	if (n < 0) return 0;
	if (n == 1) return dp[1] = data[1];
	if (n == 2) return dp[2] = data[1] + data[2];
	if (dp[n] != 0) return dp[n];
	else
		return dp[n] = isMax(recur(n-2), recur(n-3) + data[n-1]) + data[n];
}

void solve() {

	printf("\n%d\n", recur(s));
}

int main(void) {
	clock_t start, end;
	double result;

	scanf("%d", &s);

	for (int i = 1; i <= s; i++) {
		scanf("%d", &data[i]);
	}
	
	start = clock();

	solve();

	printf("\n");
	end = clock();
	result = (double)(end - start);
	printf("%f\n", result / CLOCKS_PER_SEC);

	return 0;
}