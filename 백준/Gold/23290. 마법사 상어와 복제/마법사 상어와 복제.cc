#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

vector<int>v[5][5];
vector<int>v1[5][5];
vector<int>dupV[5][5];
int IsSh[5][5]; // 상어위치
int sx, sy;
int fdx[9] = {0,0,-1,-1,-1,0,1,1,1};
int fdy[9] = {0,-1,-1,0,1,1,1,0,-1};

int IsSmellSpot[5][5];
int bbSmellSpot[5][5];
int beforeIsSmellSpot[5][5];
int bbbbIsSmellSpot[5][5];

int seq = 1;

void dup1() {

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			dupV[i][j].clear();
			for (int t = 0; t < v[i][j].size(); t++) {
				dupV[i][j].push_back(v[i][j][t]);
			}
		}
	}
}

void fishMove() {

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int t = 0; t < v[i][j].size(); t++) {	
				int d = v[i][j][t];
				for (int h = 0; h < 8; h++) {
					int nx = i + fdx[d];
					int ny = j + fdy[d];
					if (IsSmellSpot[nx][ny] >= 1 || IsSh[nx][ny] == 1
						|| nx < 1 || ny < 1 || nx>4 || ny>4) {
						d--;
						if (d == 0) {
							d = 8;
						}
					}
					else {
						v1[nx][ny].push_back(d);
						break;
					}
					if (h == 7) {
						v1[i][j].push_back(d);
					}
				}
			}	
			v[i][j].clear();
		}
	}
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int t = 0; t < v1[i][j].size(); t++) {
				v[i][j].push_back(v1[i][j][t]);
			}
			v1[i][j].clear();
		}
	}
}

int dx[5] = {0, -1,0,1,0 };
int dy[5] = {0, 0,-1,0,1 };
int visited[5][5];

void sharkMove() {
	int maxFishCnt = -1;
	int ii = 0;
	int jj = 0;
	int tt = 0;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int t = 1; t <= 4; t++) {
				memset(visited, 0, sizeof(visited));
				int cnt = 0;
				int cx = sx;
				int cy = sy;		
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 1 || ny < 1 || nx>4 || ny>4) continue;
				cnt += v[nx][ny].size();
				visited[nx][ny] = 1;
				nx += dx[j];
				ny += dy[j];
				if (nx < 1 || ny < 1 || nx>4 || ny>4) continue;
				if (visited[nx][ny] == 0)
				cnt += v[nx][ny].size();
				visited[nx][ny] = 1;
				nx += dx[t];
				ny += dy[t];
				if (nx < 1 || ny < 1 || nx>4 || ny>4) continue;
				if(visited[nx][ny]==0)
				cnt += v[nx][ny].size();
				
				if (maxFishCnt < cnt) {
					maxFishCnt = cnt;
					ii = i;
					jj = j;
					tt = t;
				}
			}
		}
	}

	int cx = sx;
	int cy = sy;
	IsSh[sx][sy] = 0;
	int nx = cx + dx[ii];
	int ny = cy + dy[ii];
	if (v[nx][ny].size() > 0) {
		v[nx][ny].clear();
		IsSmellSpot[nx][ny] ++;

		if (seq > 3) {
			bbbbIsSmellSpot[nx][ny] ++;
		}
		else {
			if (seq % 3 == 1) {
				beforeIsSmellSpot[nx][ny] ++;
			}
			if (seq % 3 == 2) {
				bbSmellSpot[nx][ny] ++;
			}
			if (seq % 3 == 0) {
				bbbbIsSmellSpot[nx][ny]++;
			}
		}
	}
	nx += dx[jj];
	ny += dy[jj];
	if (v[nx][ny].size() > 0) {
		v[nx][ny].clear();
		IsSmellSpot[nx][ny]++;

		if (seq > 3) {
			bbbbIsSmellSpot[nx][ny]++;
		}
		else {
			if (seq % 3 == 1) {
				beforeIsSmellSpot[nx][ny]++;
			}
			if (seq % 3 == 2) {
				bbSmellSpot[nx][ny]++;
			}
			if (seq % 3 == 0) {
				bbbbIsSmellSpot[nx][ny]++;
			}
		}
	}
	nx += dx[tt];
	ny += dy[tt];
	if (v[nx][ny].size() > 0) {
		v[nx][ny].clear();
		IsSmellSpot[nx][ny]++;

		if (seq > 3) {
			bbbbIsSmellSpot[nx][ny]++;
		}
		else {
			if (seq % 3 == 1) {
				beforeIsSmellSpot[nx][ny]++;
			}
			if (seq % 3 == 2) {
				bbSmellSpot[nx][ny]++;
			}
			if (seq % 3 == 0) {
				bbbbIsSmellSpot[nx][ny]++;
			}
		}
	}
	sx = nx;
	sy = ny;
	IsSh[sx][sy] = 1;
}

void dup2() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int t = 0; t < dupV[i][j].size(); t++) {
				v[i][j].push_back(dupV[i][j][t]);
			}
		}
	}	
}

void removeFishSmell() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (beforeIsSmellSpot[i][j]) {
				IsSmellSpot[i][j]--;
			}
			beforeIsSmellSpot[i][j] = bbSmellSpot[i][j];
			bbSmellSpot[i][j] = bbbbIsSmellSpot[i][j];
			bbbbIsSmellSpot[i][j] = 0;
		}
	}
}

void solve() {

	// 1. 상어가 모든 물고기에게 복제 마법을 시전
	dup1();
	// 2. 모든 물고기가 한 칸 이동
	fishMove();
	// 3. 상어가 연속해서 3칸 이동
	sharkMove();	

	// 4. 두 번 전 연습에서 생긴 물고기의 냄새가 격자에서 사라짐
	if (seq >=3) {
		removeFishSmell();
	}
	// 5. 복제 마법이 완료
	dup2();
	seq++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, s;
	cin >> m >> s;
	for (int i = 0; i < m; i++) {
		int fx, fy, d;
		cin >> fx >> fy >> d;
		v[fx][fy].push_back(d);
	}
	cin >> sx >> sy;
	IsSh[sx][sy] = 1;

	while (s--) {
		solve();
	}
	int ans = 0;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			ans += v[i][j].size();
		}
	}
	cout << ans;
}