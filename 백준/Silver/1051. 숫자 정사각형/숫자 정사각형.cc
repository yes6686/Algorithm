#include <iostream>
using namespace std;


string s[51];
int arr[51][51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[i][j] - '0';
		}
	}
	
	int max = -1;
	int k = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			k = 1;
			while (1) {
				if (i + k >= n || j + k >= m) break;
				if (arr[i][j] == arr[i + k][j] && arr[i][j] == arr[i][j + k]
					&& arr[i][j] == arr[i + k][j + k]) {
					if (max < (k+1) * (k+1)) {
						max =( k+1) * (k+1);
					}
				}
				k++;
			}
		}
	}
	if (max == -1) { cout << 1; }
	else
		cout << max;



}