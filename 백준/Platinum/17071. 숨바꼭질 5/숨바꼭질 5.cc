#include <iostream>
#include <queue>
using namespace std;

queue<pair<pair<int, int>, int>>q;
int n, k;
int visited[500001][2];

int bfs(int x, int k) {
	q.push({ {x,k},0 });
	visited[x][0] = 1;
	while (!q.empty()) {
		int kx = q.front().first.first;
		int kk = q.front().first.second;
		int s = q.front().second;
		q.pop();
		
		if (kk > 500000) return -1;
		if (visited[kk][s % 2]) {
			return s;
		}
		if (kx - 1 > 0 && visited[kx - 1][(s + 1) % 2] == 0) {
			visited[kx - 1][(s + 1) % 2] = 1;
			q.push({ {kx - 1,kk + s+1},s + 1 });
		}
		if (visited[kx + 1][(s + 1) % 2] == 0) {
			visited[kx + 1][(s + 1) % 2] = 1;
			q.push({ {kx + 1,kk + s+1},s + 1 });
		}
		if (kx * 2 <= 500000 && visited[kx * 2][(s + 1) % 2] == 0) {
			visited[kx * 2][(s+1) % 2] = 1;
			q.push({ {kx * 2,kk + s+1},s + 1 });
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	cout<<bfs(n, k);
}