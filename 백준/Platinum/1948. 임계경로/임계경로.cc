#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int>v[10001];
vector<int>rv[10001];

queue<int>q;

int Time[10001][10001];
int inDegree[10001];
int dp[10001];
int cnt = 0;
int start,e;

void dfs(int x, int value) {

	if (value == dp[x]) {
		cnt++;
	}
	else {
		return;
	}
	if (x == start) {
		return;
	}
	for (int i = 0; i<rv[x].size(); i++) {
		
		int h = rv[x][i];
		if (Time[h][x]==0) return;
		dfs(h,value-Time[h][x]);
		Time[h][x] = 0;
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	int a, b, t;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> t;
		v[a].push_back(b);
		rv[b].push_back(a);
		inDegree[b]++;
		Time[a][b] = t;

	}
	cin >> start >> e;
	for (int i = start; i <= e; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	for (int i = start; i <= e; i++) {
		int k = q.front();
		q.pop();

		for (int j = 0; j < v[k].size(); j++) {
			int h = v[k][j];
			inDegree[h]--;
			dp[h] = max(dp[h], Time[k][h] + dp[k]);

			if (inDegree[h] == 0) {
				q.push(h);
			}
		}
	}
	dfs(e, dp[e]);
	cout << dp[e] << '\n'<<cnt-1;


}