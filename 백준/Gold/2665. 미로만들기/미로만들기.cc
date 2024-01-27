#include <iostream>
#include <queue>
#define INF 1e9
using namespace std;

int arr[51][51];
int dis[51][51];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

priority_queue<pair<pair<int, int>,int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>>pq;

void djk(int a, int b,int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dis[i][j] = INF;
		}
	}
	dis[a][b] = arr[a][b];
	pq.push({ {a,b},dis[a][b] });
	while (!pq.empty()) {
		int kx = pq.top().first.first;
		int ky = pq.top().first.second;
		int cost = pq.top().second;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			int ncost = arr[nx][ny];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (dis[nx][ny] > cost + ncost) {
				dis[nx][ny] = cost + ncost;
				pq.push({ {nx,ny},dis[nx][ny] });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			arr[i][j] = s[j]-'0';
			arr[i][j] = (arr[i][j] == 1) ? 0 : 1;
		}
	}
	djk(0, 0, n);
	cout << dis[n - 1][n - 1];
}