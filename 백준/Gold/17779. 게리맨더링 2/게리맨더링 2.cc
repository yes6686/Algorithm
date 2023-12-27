#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int arr[21][21];
int arr1[21][21];

int n;

int sum[6];

int minans = 1e9;

void di(int x, int y, int d1, int d2) {
	int maxsum = -1;
	int minsum = 40001;
	for (int i = 0; i < d1+1; i++) { // 1
		if (y-i <= 0) break;
		if (x + i > n) break;
		arr1[x + i][y -i] = 5;
	}
	for (int i = 0; i < d2 + 1; i++) { // 2
		if (y + i > n) break;
		if (x + i > n) break;
		arr1[x + i][y + i] = 5;
	}
	for (int i = 0; i < d2 + 1; i++) { // 3
		if (y -d1+ i > n) break;
		if (x +d1+ i > n) break;
		arr1[x+d1 + i][y-d1 + i] = 5;
	}
	for (int i = 0; i < d1 + 1; i++) { // 4
		if (y + d2 - i <=0) break;
		if (x + d2 + i > n) break;
		arr1[x + d2 + i][y + d2 - i] = 5;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr1[i][j] == 5) {
				int check = 1;
				for (int t = j + 1; t <= n; t++) {
					if (arr1[i][t] == 5) {
						for (int h = j; h <= t; h++) {
							arr1[i][h] = 5;
						}
						check = 0;
						break;
					}
				}
				if (check == 0) break;
			}
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr1[i][j] == 5) { 
				sum[5] += arr[i][j]; 

			}
			else if (i < x + d1 && j <= y) { 
				sum[1] += arr[i][j]; 
			}
			else if (i <= x + d2 && j > y) {
				sum[2] += arr[i][j];
			}
			else if (i > x + d2 && j >= y - d1 + d2) {
				sum[4] += arr[i][j];
		}
			else if (i >= x + d1 && j < y - d1 + d2) {
				sum[3] += arr[i][j];
			}
		}
	}

	int ccheck = 1;
	for (int i = 1; i <= 5; i++) {
		if (sum[i] == 0) ccheck = 0;
		maxsum = max(maxsum, sum[i]);
		minsum = min(minsum, sum[i]);
		sum[i] = 0;
	}
	
	if (ccheck) {
		minans = min(minans, maxsum - minsum);
	}
	memset(arr1, 0, sizeof(arr1));

}



int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int t = 1; t <= n; t++) {
				for (int h = 1; h <= n; h++) {
					if(i+t+h<=n && j-t>=1 && j-t<=n && j+h<=n)
					di(i, j, t, h);
				}
			}
		}
	}



	cout << minans;
}