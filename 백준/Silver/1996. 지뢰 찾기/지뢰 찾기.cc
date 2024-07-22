#include <iostream>
using namespace std;

int arr[1001][1001];

int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int dy[8] = { -1,-1,-1,0,0,1,1,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '.') {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = s[j] - '0';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > 0) {
				cout << "*";
			}
			else {
				int cnt = 0;
				for (int t = 0; t < 8; t++) {
					int nx = i + dx[t];
					int ny = j + dy[t];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (arr[nx][ny] > 0) {
						cnt += arr[nx][ny];
					}
				}
				if (cnt >= 10) {
					cout << "M";
				}
				else {
					cout << cnt;
				}
			}
		}
		cout << '\n';
	}
}