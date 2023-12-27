#include <iostream>
#include <queue>
using namespace std;

queue<int>q;

int visited[106];
int arrl[106];
int arrs[106];

int ans[106];
int mi = 100;

void bfs(int x) {
	q.push(x);

	while (!q.empty()) {
		int kx = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++) {
			int nx = kx + i;
			if (nx >= 100) {
				if (mi > ans[kx] + 1) {
					mi = ans[kx] + 1;
				}
			}
			else {
				
				if (arrl[nx]) {
					if (visited[arrl[nx]]) continue;
					visited[arrl[nx]] = 1;
					ans[arrl[nx]] = ans[kx] + 1;
					q.push(arrl[nx]);
				}
				else if (arrs[nx]) {
					if (visited[arrs[nx]]) continue;
					visited[arrs[nx]] = 1;
					ans[arrs[nx]] = ans[kx] + 1;
					q.push(arrs[nx]);
				}
				else {
					if (visited[nx]) continue;
					visited[nx] = 1;
					ans[nx] = ans[kx] + 1;
					q.push(nx);
				}
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		arrl[x] = y;
	}
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		arrs[u] = v;
	}
	bfs(1);
	cout << mi;
}