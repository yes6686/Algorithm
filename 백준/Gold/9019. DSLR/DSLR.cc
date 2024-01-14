#include <iostream>
#include <string>
#include <string.h>
#include <queue>
using namespace std;

queue<pair<int,string>>q;
int visited[10001];
int a, b;
void bfs() {
	while (!q.empty()) {
		int kx = q.front().first;
		string op = q.front().second;
		if (kx == b) {
			cout << op << '\n';
			return;
		}
		q.pop();
		int nx;
		nx = (2 * kx) % 10000; // D
		if (!visited[nx]) {
			visited[nx] = 1;	q.push({ nx,op + "D" });
		}
		nx = (kx == 0) ? 9999 : kx - 1;
		if (!visited[nx]) {
			visited[nx] = 1;	q.push({ nx,op + "S" });
		}
		nx = (kx % 1000) * 10 + (kx / 1000); // L
		if (!visited[nx]) {
			visited[nx] = 1;	q.push({ nx,op + "L" });
		}
		nx = (kx % 10) * 1000 + (kx / 10); // R
		if (!visited[nx]) {
			visited[nx] = 1;	q.push({ nx,op + "R" });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		cin >> a >> b;
		q.push({a,""});
		visited[a] = 1;
		bfs();
		memset(visited, 0, sizeof(visited));
		while (!q.empty()) q.pop();
	}	
}