
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int s;
int dp[101];

int recur(int n) {
	if (n <= 0) return 1;
	if (n == 1) return dp[1] = 1;
	if (n == 2) return dp[2] = 2;
	if (dp[n] != 0) return dp[n];
	else
		return dp[n] = (recur(n-1) + recur(n-2) + recur(n-3))%1000;
}

void solve() {
	printf("\n%d\n", recur(s));
}

int main(void) {
	clock_t start, end;
	double result;

	scanf("%d", &s);
		
	start = clock();

	solve();

	printf("\n");
	end = clock();
	result = (double)(end - start);
	printf("%f\n", result / CLOCKS_PER_SEC);

	return 0;
}