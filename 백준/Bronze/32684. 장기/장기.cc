#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int arr[6] = { 13,7,5,3,3,2 };

	int sum1 = 72;
	double sum2 = 73.5;

	for (int i = 0;i < 6;i++) {
		int n;
		scanf("%d", &n);
		sum1 += n * arr[i];
	}

	for (int i = 0;i < 6;i++) {
		int n;
		scanf("%d", &n);
		sum2 += n * arr[i];
	}
	if (sum1 > sum2) {
		printf("cocjr0208");
	}
	else {
		printf("ekwoo");
	}
	return 0;
}