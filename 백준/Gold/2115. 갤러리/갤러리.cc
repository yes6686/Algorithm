#include <iostream>
using namespace std;

int arr[1001][1001];
int rvisited[1001][1001];
int cvisited[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'X') arr[i][j] = 1;
		}
	}

	int ans = 0;

	// 세로 검사
	for (int i = 1; i < m-2; i++) {
		for (int j = 0; j < n-1; j++) {
			if (arr[i][j] == 1 && arr[i + 1][j] == 1) {
				if (arr[i][j + 1] == 0 && arr[i + 1][j + 1] == 0) {
					if (rvisited[i][j] == 0 && rvisited[i + 1][j] == 0) {
						rvisited[i][j] = 1;
						rvisited[i+1][j] = 1;
						ans++;
					}
				}
			}
			else if (arr[i][j] == 0 && arr[i + 1][j] == 0) {
				if (arr[i][j + 1] == 1 && arr[i + 1][j + 1] == 1) {
					if (rvisited[i][j] == 0 && rvisited[i + 1][j] == 0) {
						rvisited[i][j] = 1;
						rvisited[i + 1][j] = 1;
						ans++;
					}
				}
			}
		}
	}

	// 가로 검사
	for (int i = 0; i < m - 1; i++) {
		for (int j = 1; j < n - 2; j++) {
			if (arr[i][j] == 1 && arr[i][j+1] == 1) {
				if (arr[i+1][j] == 0 && arr[i + 1][j + 1] == 0) {
					if (cvisited[i][j] == 0 && cvisited[i][j+1] == 0) {
						cvisited[i][j] = 1;
						cvisited[i][j+1] = 1;
						ans++;
					}
				}
			}else if (arr[i][j] == 0 && arr[i][j + 1] == 0) {
				if (arr[i + 1][j] == 1 && arr[i + 1][j + 1] == 1) {
					if (cvisited[i][j] == 0 && cvisited[i][j + 1] == 0) {
						cvisited[i][j] = 1;
						cvisited[i][j + 1] = 1;
						ans++;
					}
				}
			}			
		}
	}
	cout << ans << '\n';
}