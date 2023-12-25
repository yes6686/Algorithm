#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int arr1[101][101];
int arr2[101][101];
int c[101][101];
int n, L;


int main() {
	cin >> n >> L;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr1[i][j];
			
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr2[i][j] = arr1[j][i];
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int check = 1;
		for (int j = 2; j <= n; j++) {
			if (check == 0) break;
			if (arr1[i][j] == arr1[i][j - 1]) continue;
			if (abs(arr1[i][j] - arr1[i][j - 1]) > 1) {
				check = 0;
				break;
			}
			else if (arr1[i][j] > arr1[i][j - 1]) {
				if (j <= L) {
					check = 0;
					break;
				}
				else {
					if (c[i][j - 1]) {
						check = 0;
						break;
					}
					for (int t = j - 2; t > j - 1 - L; t--) {
						if (arr1[i][j - 1] != arr1[i][t]) {
							check = 0;
							break;
						}
						else {
							if (c[i][t]) {
								check = 0;
								break;
							}
							c[i][t] = 1;
						}
					}
				}
			}
			else {
				if (j + L-1 > n) {
					check = 0;
					break;
				}
				else {

					c[i][j] = 1;
					for (int t = j + 1; t <= j + L - 1; t++) {
						if (arr1[i][j] != arr1[i][t]) {
							check = 0;
							break;
						}
						else {
							if (c[i][t] == 1) {
								check = 0;
								break;
							}
							c[i][t] = 1;
						}
					}
					if (check == 0) break;
				}
			}
		}
		if (check == 1) {
			cnt++;
		}
		
	}
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= n; i++) {
		int check = 1;
		for (int j = 2; j <= n; j++) {
			if (check == 0) break;
			if (arr2[i][j] == arr2[i][j - 1]) continue;
			if (abs(arr2[i][j] - arr2[i][j - 1]) > 1) {
				check = 0;
				break;
			}
			else if (arr2[i][j] > arr2[i][j - 1]) {
				if (j <= L) {
					check = 0;
					break;
				}
				else {
					if (c[i][j - 1]) {
						check = 0;
						break;
					}
					for (int t = j - 2; t > j - 1 - L; t--) {
						if (arr2[i][j-1] != arr2[i][t]) {
							check = 0;
							break;
						}
						else {
							if (c[i][t]) {
								check = 0;
								break;
							}
							c[i][t] = 1;
						}
					}
				}
			}
			else {
				if (j + L-1 > n) {
					check = 0;
					break;
				}
				else {

					c[i][j] = 1;
					for (int t = j + 1; t <= j + L-1; t++) {
						if (arr2[i][j] != arr2[i][t]) {
							check = 0;
							break;
						}
						else {
							if (c[i][t] == 1) {
								check = 0;
								break;
							}
							c[i][t] = 1;
						}
					}
					if (check == 0) break;
				}
			}
		}
		if (check == 1) {
			cnt++;
		}

	}
	cout << cnt;
	
}