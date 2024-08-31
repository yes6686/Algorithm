#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

vector<int> v[101];
queue<int>q;
int visited[101];
int dis[101];
int n;
int isSixOver = 0;
int isAllConnect = 1;

void bfs(int x) {
	visited[x] = 1;
	dis[x] = 0;
	for (int i = 0; i < v[x].size(); i++) {
		int k = v[x][i];
		q.push(k);
		dis[k] = 1;
		visited[k] = 1;
	}
	isSixOver = 0;
	isAllConnect = 1;
	while (!q.empty()) {
		int nn = q.front();
		q.pop();
		for (int i = 0; i < v[nn].size(); i++) {
			int k = v[nn][i];
			if (visited[k] == 1) continue;
			visited[k] = 1;
			dis[k] = dis[nn] + 1;
			q.push(k);
			if (dis[k] > 6) isSixOver = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			isAllConnect = 0;
			break;
		}
    }
	memset(visited, 0, sizeof(visited));
	memset(dis, 0, sizeof(dis));

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		bfs(i);
		if (isSixOver == 1 || isAllConnect == 0) {
			cout << "Big World!" << '\n';
			return 0;
		}
	}
	cout << "Small World!" << '\n';
}