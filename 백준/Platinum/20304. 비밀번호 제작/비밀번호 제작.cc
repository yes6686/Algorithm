#include <iostream>
#include <queue>
using namespace std;

int visited[3000001];
int n;

queue<pair<int,int>>q;

void bfs(int x) {
	q.push({ x,1 });
	visited[x] = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cd = q.front().second;
		q.pop();

		for (int i = 1;i <= n;i *= 2) {
			int k = (cx ^ i);
			if (visited[k] == 0) {
				visited[k] = cd+1;
				q.push({ k,cd + 1 });
			}
			else if (visited[k] > cd + 1) {
				visited[k] = cd + 1;
				q.push({ k,cd + 1 });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int m;
	cin >> m;

	for (int i = 0;i < m;i++) {
		int x;
		cin >> x;
		bfs(x);
	}


	int maxAns = 0;

	for (int i = 0;i <= n;i++) {
		
		maxAns = max(maxAns, visited[i]);
	}

	cout << maxAns-1 << '\n';

}