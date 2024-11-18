#include <iostream>
using namespace std;

int visited[5001][5001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m;
	cin >> n >> m;
	visited[m - 1][0] = 1;
	int x = m - 1;
	int y = 0;
	int d = 1;
    int s = 2;
    int a = 0,b=0;
	while (true) {
		if (s > n * m) {
			cout << a << ' ' << b << '\n';
			break;
		}
		if (d > 4) {
			d = 1;
		}
		if (d == 1) {
			if (y + 1 >= n) { // 벽
				d++;
			}
			else if (visited[x][y + 1] == 0) {
				visited[x][y + 1] = 1;
				s++;
				a++;
				y++;
			}
			else { // 이미 방문한 곳
				d++;
			}
		}
		else if (d == 2) {
			if (x - 1 < 0) { // 벽
				d++;
			}
			else if (visited[x - 1][y] == 0) {
				visited[x - 1][y] = 1;
				s++;
				b++;
				x--;
			}
			else { // 이미 방문한 곳
				d++;
			}
		}
		else if (d == 3) {
			if (y - 1 < 0) { // 벽
				d++;
			}
			else if (visited[x][y - 1] == 0) {
				visited[x][y - 1] = 1;
				s++;
				a--;
				y--;
			}
			else { // 이미 방문한 곳
				d++;
			}
		}
		else {
			if (x + 1 >= m) { // 벽
				d++;
			}
			else if (visited[x + 1][y] == 0) {
				visited[x + 1][y] = 1;
				s++;
				b--;
				x++;
			}
			else { // 이미 방문한 곳
				d++;
			}
		}
	}
}