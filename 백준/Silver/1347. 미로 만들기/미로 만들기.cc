#include <iostream>
using namespace std;

int arr[51];
int map[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	string s;
	cin >> s;
	// 동 : 1, 서 : 2, 남 : 3, 북 : 4
	int d = 3;
	int x = 50;
	int y = 50;
	map[x][y] = 1;
	int minX=50;
	int minY=50;
	int maxX=50;
	int maxY=50;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') {
			if (d == 1) { // 동
				d = 3;
			}
			else if (d == 2) { // 서
				d = 4;
			}
			else if (d == 3) { // 남
				d = 2;
			}
			else { // 북
				d = 1;
			}
		}
		else if (s[i] == 'L') {
			if (d == 1) { // 동
				d = 4;
			}
			else if (d == 2) { // 서
				d = 3;
			}
			else if (d == 3) { // 남
				d = 1;
			}
			else { // 북
				d = 2;
			}
		}
		else {
			if (d == 1) { // 동
				y += 1;
			}
			else if (d == 2) { // 서
				y -= 1;
			}
			else if (d == 3) { // 남
				x += 1;
			}
			else { // 북
				x -= 1;
			}
			map[x][y] = 1;
			minX = min(minX, x);
			minY = min(minY, y);
			maxX = max(maxX, x);
			maxY = max(maxY, y);
		}
	}
	for (int i = minX; i <= maxX; i++) {
		for (int j = minY; j <= maxY; j++) {
			if (map[i][j] == 1) {
				cout << ".";
			}
			else {
				cout << "#";
			}
		}
		cout << '\n';
	}
}