#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

vector<int>v[100001];
queue<int>q;
int visited[100001];
int checked[100001];


void dfs(int s, int x,int d) {

	int k = v[x].front();
	if (checked[k] == -1 || checked[k]==1) {

		while (!q.empty()) {
			int qk = q.front();
			q.pop();
			checked[qk] = -1;
		}
		return;
	}
	
	if (visited[k] == 1) {
		int ch = 0;
		while (!q.empty()) {
			int qk = q.front();
			q.pop();
			if (qk == k) {
				ch = 1;
			}
			if (ch == 1) {
				checked[qk] = 1;
			}
			else {
				checked[qk] = -1;
			}
		}
		while (!q.empty()) q.pop();
		return;
	}
	visited[k] = 1;
	q.push(k);
	dfs(s, k,d+1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1;i <= n;i++) {
			int x;
			cin >> x;
			v[i].push_back(x);
		}

		for (int i = 1;i <= n;i++) {
			if (visited[i]==1) continue;
			visited[i] = 1;
			q.push(i);
			dfs(i, i, 0);
		}

		int cnt = 0;
		for (int i = 1;i <= n;i++) {
			if (checked[i] == -1) {
				//cout << " i :" << i << '\n';
				cnt++;
			}
			v[i].clear();
		}
		cout << cnt << '\n';
		memset(checked, 0, sizeof(checked));
		memset(visited, 0, sizeof(visited));
	}
}