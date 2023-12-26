#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

int arr[22][22];
int visited[22][22];
int dis[22][22];
queue<pair<int, int>>q;
queue<pair<int, int>>sq;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 }; 
int n;

void bfs(int x, int y,int siz,int val,int tim) {
	q.push(make_pair(x, y));


	int mindis = 401;
	while (!q.empty()) {
		int kx = q.front().first;
		int ky = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
			if (arr[nx][ny] > siz || visited[nx][ny]!=0) continue;
			q.push(make_pair(nx, ny));
			dis[nx][ny] = dis[kx][ky] + 1; 
			visited[nx][ny] = 1;

			if (arr[nx][ny] <= 6 && arr[nx][ny] >= 1) {
				if (arr[nx][ny] < siz) {
					mindis = min(mindis, dis[nx][ny]);
					sq.push(make_pair(nx, ny));
				}
			}
			
		}
	}
	int realmovei=20;
	int realmovej=20;
	if (sq.size() == 0) {
		cout << tim << '\n';
		return;
	}
	else if (sq.size() == 1) {
		int kxx = sq.front().first;
		int kyy = sq.front().second;
		sq.pop();
		arr[kxx][kyy] = 9;
		arr[x][y] = 0;
		int distance = dis[kxx][kyy];
		memset(visited, 0, sizeof(visited));
		memset(dis, 0, sizeof(dis));
		if (val + 1 == siz) {
			bfs(kxx, kyy , siz + 1, 0, tim + distance);
		}
		else {
			bfs(kxx, kyy, siz, val+1, tim + distance);
		}
		return;
	}
	else {
		while (!sq.empty()) {
			int kx = sq.front().first;
			int ky = sq.front().second;
			sq.pop();

			if (mindis == dis[kx][ky]) {

				if (realmovei > kx) {
					realmovei = kx;
					realmovej = ky;
				}
				else if(realmovei==kx) {
					if (realmovej > ky) {
						realmovei = kx;
						realmovej = ky;
					}
				}
			}

		}
	}
	int distance = dis[realmovei][realmovej];
	memset(visited, 0, sizeof(visited));
	memset(dis, 0, sizeof(dis));

	arr[x][y] = 0;
	arr[realmovei][realmovej] = 9;

	if (val + 1 == siz) {

		bfs(realmovei, realmovej, siz + 1, 0, tim +distance);
	}
	else {
		bfs(realmovei, realmovej, siz, val+1, tim + distance);

	}



}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> n;

	int shi=1;
	int shj=1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				shi = i;
				shj = j;
			}
		}
	}
	bfs(shi, shj, 2, 0, 0);



}