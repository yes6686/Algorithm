#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int visited[10001];
int cnt = 0;

vector<int>v[10001];
priority_queue<int, vector<int>, greater<int>>pq;

void dfs(int x) {
	if (visited[x] == 1) return;
	visited[x] = 1;
	cnt++;
	for (int i = 0;i < v[x].size();i++) {
		int k = v[x][i];
		dfs(k);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}

	int maxCnt = 0;

	for (int i = 1;i <= n;i++) {
		dfs(i);
		if (maxCnt < cnt) {
			while (!pq.empty()) pq.pop();
			maxCnt = max(maxCnt, cnt);
			pq.push(i);
		}
		else if (maxCnt==cnt){
			pq.push(i);
		}
		memset(visited, 0, sizeof(visited));
		cnt = 0;
	}
    
	while (!pq.empty()) {
		int k = pq.top();
		pq.pop();
		cout << k << " ";
	}
}