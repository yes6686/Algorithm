#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	if (n % 2024 == 0 && n<=100000) {
		printf("Yes");
	}
	else {
		printf("No");
	}
}