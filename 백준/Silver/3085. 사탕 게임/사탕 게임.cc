#include <iostream>
#include <string.h>
using namespace std;

char c[51][51];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; 
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			c[i][j] = s[j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cnt = 1;
			for (int a = 1; a < n; a++) {
				if (c[i][a] == c[i][a - 1]) {
					cnt++;
					ans = max(ans, cnt);
				}
				else {
					cnt = 1;
				}
			}
			cnt = 1;
			for (int a = 1; a < n; a++) {
				if (c[a][j] == c[a - 1][j]) {
					cnt++;
					ans = max(ans, cnt);
				}
				else {
					cnt = 1;
				}
			}
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || ny < 0
					|| nx >= n || ny >= n) {
					continue;
				}
				if (c[i][j] == c[nx][ny]) continue;
				char t = c[i][j];
				c[i][j] = c[nx][ny];
				c[nx][ny] = t;
				
				cnt = 1;
				for (int a = 1; a < n; a++) {
					if (c[i][a] == c[i][a - 1]) {
						cnt++;
						ans = max(ans, cnt);
					}
					else {
						cnt = 1;
					}
				}
				cnt = 1;
				for (int a = 1; a < n; a++) {
					if (c[a][j] == c[a-1][j]) {
						cnt++;
						ans = max(ans, cnt);
					}
					else {
						cnt = 1;
					}
				}
				t = c[i][j];
				c[i][j] = c[nx][ny];
				c[nx][ny] = t;
			}
		}
	}
	cout << ans << '\n';
}