#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int arr[1001][1001];
int visited[1001][1001];
int t[1001][1001];
int J[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue<pair<int, int>>q;

int r, c;

void Fbfs(int a,int b) {
	q.push({ a,b });
	t[a][b] = 0;
	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int kx = nx + dx[i];
			int ky = ny + dy[i];
			if (kx == a && ky == b) continue;
			if (arr[kx][ky] == 1 || visited[kx][ky]==1) continue;
			if (kx<0 || ky <0 || kx>=r || ky>=c) continue;
			visited[kx][ky] = 1;
			if (t[kx][ky] == 0) {
				t[kx][ky] = t[nx][ny] + 1;
			}
			else {
				t[kx][ky] = min(t[kx][ky], t[nx][ny] + 1);
			}
			q.push({ kx,ky });
		}
	}
}

void Jbfs(int a, int b) {
	q.push({ a,b });
	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int kx = nx + dx[i];
			int ky = ny + dy[i];
			if (kx == a && ky == b) continue;
			if (arr[kx][ky] == 1 || visited[kx][ky] == 1) continue;
			if (kx < 0 || ky < 0 || kx >= r || ky >= c) continue;
			if (t[kx][ky] <= J[nx][ny] + 1 && t[kx][ky]) continue;
			visited[kx][ky] = 1;
			J[kx][ky] = J[nx][ny] + 1;
			q.push({ kx,ky });
		}
	}
}

int main() {
	cin >> r >> c;
	char ch;
	int Jindexi,Jindexj;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> ch;
			if (ch == '#') {
				arr[i][j] = 1;
			}
			else if (ch == '.') {
				arr[i][j] = 2;
			}
			else if (ch == 'J') {
				arr[i][j] = 3;
				Jindexi = i; Jindexj = j;
			}
			else if(ch=='F') {
				arr[i][j] = 4;
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 4) {
				Fbfs(i, j);
				memset(visited, 0, sizeof(visited));
			}
		}
	}
	Jbfs(Jindexi, Jindexj);
	int mi = 1000001;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i != 0 && j != 0 && i != r - 1 && j != c - 1) continue;
			if (arr[i][j] == 2 && J[i][j]) {
				mi = min(mi, J[i][j]);	
			}
			else if (arr[i][j] == 3) { // 가장자리에 J가 있는 경우
				mi = 0;
			}
		}
	}
	if (mi == 1000001) {
		cout << "IMPOSSIBLE";
	}
	else {
		cout << mi+1;
	}
}