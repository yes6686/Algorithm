#include <iostream>
#include <queue>
using namespace std;

vector<int>v[20001];
int visited[20001];

queue<pair<int,int>>q;

int maxDis = 0;
priority_queue<int,vector<int>,greater<int>>pq[20001];

void bfs() {
	while (!q.empty()) {
		int cx = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		for (int i = 0;i < v[cx].size();i++) {
			int k = v[cx][i];
			if (visited[k] == 0) {
				visited[k] = 1;
				q.push({ k,cnt + 1 });
				pq[cnt + 1].push(k);
				maxDis = max(maxDis, cnt + 1);
			}
		}
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
		v[a].push_back(b);
		v[b].push_back(a);
	}
	visited[1] = 1;
	q.push({ 1,0 });
	bfs();
	
	cout << pq[maxDis].top() << " " << maxDis << " " << pq[maxDis].size();
}