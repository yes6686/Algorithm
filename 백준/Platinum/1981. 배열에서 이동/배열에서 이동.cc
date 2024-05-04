#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int arr[101][101];
int visited[101][101];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int n;

queue<pair<int, int>>q;
int bfs(int minV, int maxV) {
	memset(visited, 0, sizeof(visited));
	visited[0][0] = 1;
	q.push({0,0});
	while (!q.empty()) {
		int kx = q.front().first;
		int ky = q.front().second;
		q.pop();
		if (kx == n - 1 && ky == n - 1) {
			while (!q.empty())q.pop();
			return 1;
		}
		for (int i = 0; i < 4; i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny]) continue;
			if (arr[nx][ny] > maxV || arr[nx][ny] < minV) continue;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int ma = 0;
	int mi = 200;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			ma = max(ma, arr[i][j]);
			mi = min(mi, arr[i][j]);
		}
	}
	int s = 0;
	int e = ma-mi;
	int r = 200;
	while (s <= e) {

		int mid = (s + e) / 2;
		int check = 0;
		for (int i = mi; i <= ma-mid; i++) {
			if (arr[0][0] >= i && arr[0][0] <= i + mid) {
				if (bfs(i, i + mid) == 1) {
					check = 1;
					break;
				}
			}
		}
		if (check == 1) {
			e = mid - 1;
			r = min(r, mid);
		}
		else {
			s = mid + 1;
		}
	}
	cout << r;
}