#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int>v[32001];
queue<int>q;

int inDegree[32001];
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		inDegree[y]++;
	}
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int k = q.front();
		q.pop();
		cout << k << ' ';
		for (int i = 0; i < v[k].size(); i++) {
			int j = v[k][i];
			inDegree[j]--;
			if (inDegree[j] == 0) {
				q.push(j);
			}
		}
	}
}