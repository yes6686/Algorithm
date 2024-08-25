#include <iostream>
#include <vector>
using namespace std;

vector<int>v[101];
int visited[101];

int ans = 0;

void dfs(int x) {

	for (int i = 0; i < v[x].size(); i++) {
		int k = v[x][i];
		if (visited[k] == 0) {
			visited[k] = 1;
			ans++;
			dfs(k);
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int x;
	cin >> x;
	for (int i = 0; i < x; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	if (ans == 0) {
		cout << 0;
	}
	else {
		cout << ans-1 << '\n';
	}
}