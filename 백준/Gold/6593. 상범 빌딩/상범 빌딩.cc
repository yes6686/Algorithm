#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int arr[31][31][31]; // 층, 행, 열
int dis[31][31][31]; // 층, 행, 열
int visited[31][31][31]; // 층, 행, 열

queue<pair<int , pair<int, int>>>q;

// 동, 서, 남, 북, 상, 하
int dh[6] = { 0,0,0,0,1,-1 };
int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 1,-1,0,0,0,0 };

int L, R, C;
int minAns = 1e9;

void bfs(int h, int x, int y) {
	q.push({ h,{x,y} });
	visited[h][x][y] = 1;
	while (!q.empty()) {
		int kh = q.front().first;
		int kx = q.front().second.first;
		int ky = q.front().second.second;
		q.pop();
		
		for (int i = 0; i < 6; i++) {
			int nh = kh + dh[i];
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if (nh < 0 || nx < 0 || ny < 0) continue;
			if (nh >= L || nx >= R || ny >= C) continue;
			if (visited[nh][nx][ny] == 1) continue;
			if (arr[nh][nx][ny] == 2) continue;
			visited[nh][nx][ny] = 1;
			dis[nh][nx][ny] = dis[kh][kx][ky] + 1;
			if (arr[nh][nx][ny] == 4) {
				minAns = min(minAns, dis[nh][nx][ny]);
				continue;
			}
			q.push({ nh,{nx,ny} });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				string s;
				cin >> s;
				for (int t = 0; t < s.size(); t++) {
					if (s[t] == '.') { // 비어있는 칸
						arr[i][j][t] = 1;
					}
					else if (s[t] == '#') { // 지나갈 수 없는 칸
						arr[i][j][t] = 2;
					}
					else if (s[t] == 'S') { //시작 지점
						arr[i][j][t] = 3;
					}
					else if (s[t] == 'E') { // 출구
						arr[i][j][t] = 4;
					}
				}
			}
		}
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int t = 0; t < C; t++) {
					if (arr[i][j][t] == 3) {
						bfs(i, j, t);
					}
				}
			}
		}
		if (minAns == 1e9) {
			cout << "Trapped!" << '\n';
		}
		else {
			cout << "Escaped in " << minAns << " minute(s)." << '\n';
		}
		minAns = 1e9;
		memset(visited, 0, sizeof(visited));
		memset(dis, 0, sizeof(dis));
	}
}