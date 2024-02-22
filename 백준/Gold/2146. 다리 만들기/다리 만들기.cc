#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int arr[101][101];
int arr1[101][101];
int visited[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue<pair<int, int>>q;
int n;
int s = 0;
void bfs(int x, int y) {
	q.push({ x,y });
	visited[x][y] = 1;
	arr[x][y] = s;
	while (!q.empty()) {
		int kx = q.front().first;
		int ky = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny] || arr[nx][ny]==0) continue;
			visited[nx][ny] = 1;
			if (arr[nx][ny] == 1) {
				arr[nx][ny] = s;
				q.push({ nx,ny });
			}
		}
	}
}

int minAns = 201;

void solve(int x, int y,int k) {
	q.push({ x,y });
	while (!q.empty()) {
		int kx = q.front().first;
		int ky = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny]) continue;
			visited[nx][ny] = 1;
			if (arr[nx][ny] == k) {
				q.push({ nx,ny });
			}
			else if (arr[nx][ny] == 0) {
				if (arr1[nx][ny] == 0) {
					arr1[nx][ny] = arr1[kx][ky]+1;
				}
				else {
					arr1[nx][ny] = min(arr1[nx][ny], arr1[kx][ky] + 1);
				}

				//arr1[nx][ny] = arr1[kx][ky] + 1;
				q.push({ nx,ny });
			}
			else {
				minAns = min(minAns, arr1[kx][ky]);
			}	
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	queue<pair<int,int>>qq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0 && arr[i][j] == 1) {
				s++;
				bfs(i, j);		
			}
			if (arr[i][j]) {
				qq.push({ i,j });
			}
		}
	}
	memset(visited, 0, sizeof(visited));
	while (!qq.empty()) {
		int x = qq.front().first;
		int y = qq.front().second;
		qq.pop();
		solve(x, y, arr[x][y]);
		memset(visited, 0, sizeof(visited));	
		memset(arr1, 0, sizeof(arr1));	
	}
	cout << minAns;
}