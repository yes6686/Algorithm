#include <iostream>
using namespace std;

int arr[201][201];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c, n;
	cin >> r >> c >> n;

	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '.') {
				arr[i][j] = -1;
			}
			else {
				arr[i][j] = 0;
			}
		}
	}

	n--;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] != -1) {
				arr[i][j]++;
			}
		}
	}
	while (n) {
		n--;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j] == -1) {
					arr[i][j] = 0;
				}
				else {
					arr[i][j]++;
				}
			}
		}
		if (n == 0) break;
		n--;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j] != -1) {
					arr[i][j]++;
				}
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j] == 3) {
					arr[i][j] = -1;
					for (int a = 0; a < 4; a++) {
						int nx = i + dx[a];
						int ny = j + dy[a];
						if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
						if (arr[nx][ny] == 3) continue;
						arr[nx][ny] = -1;
					}
				}
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == -1) {
				cout << ".";
			}
			else {
				cout << "O";
			}
		}
		cout << '\n';
	}
}