#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<int>v[10001];
priority_queue<int, vector<int>, greater<int>>pq;
int visited[10001];
set<int>s;
int d[10001];

int dfs(int n, int x,int check) {
	visited[x] = n;
	int minD = n;
	int cnt = 0;
	for (int i = 0; i < v[x].size(); i++) {
		int k = v[x][i];
		if (visited[k] == 0) {
			cnt++;
			int kk = dfs(n + 1, k,0);
			if (check==0 && kk >= visited[x]) {
				s.insert(x);
			}
			minD = min(minD, kk);
		}
		else {
			minD = min(minD, visited[k]);
			continue;
		}
	}
	if (check == 1 && cnt > 1) {
		s.insert(x);
	}
	return minD;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int V, E;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		d[a]++;
		d[b]++;
	}
	for (int i = 1; i <= V; i++) {
		if (visited[i] == 0) {
			dfs(1, i,1);
		}
	}

	set<int>::iterator iter;

	for (iter = s.begin(); iter != s.end(); iter++) {
		int k = *iter;
		if (d[k] > 1) {
			pq.push(k);
		}
	}
	cout << pq.size() << '\n';
	while (!pq.empty()) {
		cout << pq.top()<< ' ';
		pq.pop();
	}
}