
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool isSamecol[101];
bool isSamediag1[101];
bool isSamediag2[101];

int cnt;
int n;
int a[1000001];

void queens(int cur) {
	if (cur == n) {
		cnt++;
		if (cnt <= 3) {
			for (int i = 0; i < n; i++) {
				printf("%d ", a[i] + 1);
			}
			printf("\n");
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!isSamecol[i] && !isSamediag1[cur+i] && !isSamediag2[cur-i+n-1]) {
			isSamecol[i] = 1;
			isSamediag1[cur+i] = 1;
			isSamediag2[cur - i + n - 1] = 1;
			a[cur] = i;
			queens(cur + 1);
			isSamecol[i] = 0;
			isSamediag1[cur + i] = 0;
			isSamediag2[cur - i + n - 1] = 0;
		}
	}
}

int main() {
	clock_t start, end;
	double result;

	scanf("%d", &n);

	start = clock();
	queens(0);
	printf("%d\n", cnt);
	printf("\n");
	end = clock();
	result = (double)(end - start);
	printf("%f\n", result / CLOCKS_PER_SEC);

	return 0;
}