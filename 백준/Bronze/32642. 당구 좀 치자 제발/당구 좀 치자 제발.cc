#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int n;
	scanf("%d", &n);

	long long int ans = 0;
	int k = 0;

	for (int i = 0;i < n;i++) {
		int x;
		scanf("%d", &x);
		if (x == 0) {
			k--;
		}
		else {
			k++;
		}
		ans += k;
	}
	printf("%lld", ans);
}