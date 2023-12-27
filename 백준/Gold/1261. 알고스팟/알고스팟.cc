#include <iostream>
#include <vector>
#include <queue>
using namespace std;

string s[101];
int arr[101][101];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int m, n;
vector<pair<int, int>>v[101];
priority_queue<pair<int, int>>pq;

int d[101][101];

void dsk(int x,int y) {
	pq.push({ x,y });
	while (!pq.empty()) {
		int nx = pq.top().first;
		int ny = pq.top().second;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int kx = nx + dx[i];
			int ky = ny + dy[i];
			if (kx <= 0 || ky <= 0 || kx > n || ky > m) continue;
			if (d[kx][ky] > d[nx][ny] + arr[nx][ny]) {
				d[kx][ky] = d[nx][ny] + arr[nx][ny];
				pq.push({ kx,ky });
			}
		}



	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> m >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			d[i][j] = 1e9;
		}
	}

	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0 ; j < m; j++) {
			arr[i + 1][j + 1] = s[i][j] - '0';
		}
	}
	d[1][1] = 0;
	dsk(1, 1);
	cout << d[n][m];

}