#include <stdio.h>

int dpA[100] = { 0 };
int dpB[100] = { 0 };
int fiboA(int n) {
	dpA[0] = 1;
	dpA[1] = 0;
	for (int i = 2; i <= n; i++) {
		dpA[i] = dpA[i - 1] + dpA[i - 2];
	}
	return dpA[n];
}
int fiboB(int n) {
	dpB[0] = 0;
	dpB[1] = 1;
	for (int i = 2; i <= n; i++) {
		dpB[i] = dpB[i - 1] + dpB[i - 2];
	}
	return dpB[n];
}
int main(void) {
	int n;
	scanf("%d", &n);
	int k;

	for (int i = 0; i < n; i++) {

		scanf("%d", &k);
		

		printf("%d %d\n", fiboA(k), fiboB(k));
	}
	return 0;
}