#include <iostream>
using namespace std;

int arr[6][6];
int visited[6][6];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


int r, c, k;
int ans = 0;

void go(int a,int b,int d) {

	if (a == 0 && b == c - 1) {

		if (k == d) ans++;

		return;	
	}

	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + a;
		int ny = dy[i] + b;
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
		if (visited[nx][ny] == 1 || arr[nx][ny] == 1) continue;
		visited[nx][ny] = 1;
		go(nx, ny, d + 1);
		visited[nx][ny] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c >> k;

	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'T') {
				arr[i][j] = 1;
			}
		}
	}
	visited[r - 1][0] = 1;
	go(r - 1, 0, 1);

	cout << ans << '\n';
}