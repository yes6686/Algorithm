#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int n;
	scanf("%d", &n);

	int y = 2024;
	int m = 8 + 7 * (n-1);

	int d = (m % 12 == 0) ? m / 12 - 1 : m / 12;
	m -= (d * 12);

	printf("%d %d", y + d, m);
	return 0;
}