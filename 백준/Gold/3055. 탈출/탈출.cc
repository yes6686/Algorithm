#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int arr[51][51];
int w[51][51];
int visited[51][51];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int Dx, Dy; // 비버의 굴 위치
int sx, sy; // 고슴도치의 초기 위치
int r, c;

int minAns = 251;

queue<pair<int, int>>q;
queue<pair<int, int>>ww;

void bfs(int x, int y,int k) {
	q.push({ x,y });
	visited[x][y] = 1;
	if (k == 1) {
		w[x][y] = 0;
	}
	while (!q.empty()) {
		int kx = q.front().first;
		int ky = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (arr[nx][ny] == -1) continue;
			if (visited[nx][ny] == 1) continue;
			visited[nx][ny] = 1;
			 
			if (k == 1) { // 물
				if (Dx != nx || Dy != ny) {
					if (w[nx][ny] > 0 && (w[nx][ny] > w[kx][ky]+1)) {
						w[nx][ny] = min(w[nx][ny], w[kx][ky] + 1);
						q.push({ nx,ny });
					}
					else if(w[nx][ny]==0) {
						w[nx][ny] = w[kx][ky] + 1;
						q.push({ nx,ny });
					}
				}
			}
			else { // 고슴도치

				if (Dx == nx && Dy == ny) {
					minAns = min(minAns, arr[kx][ky] + 1);
				}
				else {
					if (w[nx][ny]==0 || (arr[kx][ky] + 1 < w[nx][ny])) {
						arr[nx][ny] = arr[kx][ky] + 1;
						q.push({ nx,ny });
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;
	for (int i = 0;i < r;i++) {
		string s;
		cin >> s;
		for (int j = 0;j < s.size();j++) {
			if (s[j] == 'S') {
				sx = i;
				sy = j;
			}
			else if (s[j] == 'D') {
				Dx = i;
				Dy = j;
			}
			else if (s[j] == '*') {
				ww.push({ i,j });
			}
			else if (s[j]=='X') {
				arr[i][j] = -1;
			}
		}
	}

	while (!ww.empty()) {
		int kx = ww.front().first;
		int ky = ww.front().second;
		ww.pop();
		bfs(kx, ky, 1);
		memset(visited, 0, sizeof(visited));

	}

	bfs(sx, sy, 2);

	if (minAns == 251) {
		cout << "KAKTUS" << '\n';
	}
	else {
		cout << minAns << '\n';
	}
}