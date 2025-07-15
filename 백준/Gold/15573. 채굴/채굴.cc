#include <iostream>
#include <queue>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


int arr[1001][1001];
int visited[1001][1001];
int ans = 0;
int n, m, k;
int cnt = 0;

priority_queue<pair<int, pair<int, int>>,
	vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;

void bfs() {
	
	while (!pq.empty()) {
		int cx = pq.top().second.first;
		int cy = pq.top().second.second;
		int d = pq.top().first;
		pq.pop();
		ans = max(ans, d);
		cnt++;
		if (cnt >= k) {
			cout << ans << '\n';
			return;
		}
		for (int i = 0;i < 4;i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny] == 1)  continue;
			visited[nx][ny] = 1;
			pq.push({ arr[nx][ny], {nx,ny} });
		}
	}
}

int main() {
	cin >> n >> m >> k;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> arr[i][j];
			if (i == 0 || j == 0 || j == m - 1) {
				visited[i][j] = 1;
				pq.push({ arr[i][j],{i,j} });
			}
		}
	}
	
	bfs();
}