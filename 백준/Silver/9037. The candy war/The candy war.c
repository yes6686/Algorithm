#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int T;
	scanf("%d", &T);

	int arr[11];
	int c_arr[11];
	for (int i = 0; i < 11; i++) {
		arr[i] = 0;
		c_arr[i] = 0;
	}

	while (T--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			if (arr[i] % 2 != 0) {
				arr[i]++;
			}
			c_arr[i] = arr[i];
		}

		int count = 0;
		while (1) {
			int check = 1;
			for (int i = 1; i < n; i++) {
				if (arr[i] != arr[i - 1]) {
					check = 0;
					break;
				}
			}
			if (check == 1) {
				break;
			}

			for (int i = 0; i < n; i++) {
				if (i == 0) {
					c_arr[i] += arr[n - 1] / 2;
					c_arr[i] -= arr[i] / 2;
				}
				else {
					c_arr[i] += arr[i - 1] / 2;
					c_arr[i] -= arr[i] / 2;
				}
			}

			for (int i = 0; i < n; i++) {
				if (c_arr[i] % 2 != 0) c_arr[i]++;
				arr[i] = c_arr[i];
			}
			count++;
		}
		printf("%d\n", count);
	}
}