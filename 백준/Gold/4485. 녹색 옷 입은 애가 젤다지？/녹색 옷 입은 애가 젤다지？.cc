#include <iostream>
#include <queue>
#define INF 1e9
using namespace std;

priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int arr[126][126];
int dis[126][126];

void djk(int a,int b,int n) {
	pq.push({ {a,b},arr[a][b] });
	dis[a][b] = arr[a][b];
	while (!pq.empty()) {
		int kx = pq.top().first.first;
		int ky = pq.top().first.second;
		int cost = pq.top().second;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if (nx <0 || ny <0 || nx>=n || ny>=n) continue;
			if (dis[nx][ny] > dis[kx][ky] + arr[nx][ny]) {
				dis[nx][ny] = dis[kx][ky] + arr[nx][ny];
				pq.push({ {nx,ny},arr[nx][ny] });
			}
		}
	}
}

int main() {
	int T = 1;
	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dis[i][j] = INF;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		djk(0, 0,n);
		cout <<"Problem "<<T<<": " << dis[n - 1][n - 1] << '\n';
		T++;
	}
}