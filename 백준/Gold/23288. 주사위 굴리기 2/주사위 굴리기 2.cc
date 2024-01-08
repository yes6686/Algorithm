#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int arr[21][21];
int visited[21][21];
int foward = 2,le = 4,ri = 3,up=1,back=5,bottom=6;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n, m, k;
queue<pair<int, int>>q;
int sum = 0;
int ans = 0;
void bfs(int x, int y) {
	sum = 0;
	q.push({ x,y });
	sum += arr[x][y];
	visited[x][y] = 1;
	while (!q.empty()) {
		int kx = q.front().first;
		int ky = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if (nx > n || ny > m || nx <= 0 || ny <= 0) continue;
			if (visited[nx][ny]) continue;
			if (arr[kx][ky] != arr[nx][ny]) continue;
			visited[nx][ny] = 1;
			sum += arr[nx][ny];
			q.push({ nx,ny });
		}
	}
}


void go(int depth,int dir, int x,int y) {
	if (depth == 0) { return; }
	if (dir == 1) { // 동
		if (y + 1 > m) {
			go(depth, 2, x, y);
			return;
		}
		int temp = ri;
		ri = up;
		up = le;
		le = bottom;
		bottom = temp;
		memset(visited, 0, sizeof(visited));
		bfs(x, y + 1);
		ans += sum;
		sum = 0;
		if (arr[x][y + 1] < bottom) {
			go(depth - 1, 3, x, y + 1);
		}
		else if (arr[x][y + 1] > bottom) {
			go(depth - 1, 4, x, y + 1);
		}
		else {
			go(depth - 1, 1, x, y + 1);
		}
	}
	else if (dir == 2) { // 서
		if (y - 1 ==0) {
			go(depth, 1, x, y);
			return;
		}
		int temp = le;
		le = up;
		up = ri;
		ri = bottom;
		bottom = temp;
		memset(visited, 0, sizeof(visited));
		bfs(x, y - 1);
		ans += sum;
		sum = 0;
		if (arr[x][y - 1] < bottom) {
			go(depth - 1, 4, x, y - 1);

		}
		else if (arr[x][y - 1] > bottom) {
			go(depth - 1, 3, x, y - 1);

		}
		else {
			go(depth - 1, 2, x, y - 1);
		}
	}
	else if (dir == 3) { // 남
		if (x + 1 >n) {
			go(depth, 4, x, y);
			return;
		}
		int temp = foward;
		foward = bottom;
		bottom = back;
		back = up;
		up = temp;
		memset(visited, 0, sizeof(visited));
		bfs(x + 1, y);
		ans += sum;
		sum = 0;
		if (arr[x + 1][y] < bottom) {
			go(depth - 1, 2, x + 1, y);
		}
		else if (arr[x + 1][y] > bottom) {
			go(depth - 1, 1, x + 1, y);
		}
		else {
			go(depth - 1, 3, x + 1, y);
		}
	}
	else { // 북
		if (x - 1 ==0) {
			go(depth, 3, x, y);
			return;
		}
		int temp = bottom;
		bottom = foward;
		foward = up;
		up = back;
		back = temp;
		memset(visited, 0, sizeof(visited));
		bfs(x - 1, y);
		ans += sum;
		sum = 0;
		if (arr[x - 1][y] < bottom) {
			go(depth - 1, 1, x - 1, y);

		}
		else if (arr[x - 1][y] > bottom) {
			go(depth - 1, 2, x - 1, y);
		}
		else {
			go(depth - 1, 4, x - 1, y);
		}
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	go(k, 1, 1, 1);
	cout << ans;
}