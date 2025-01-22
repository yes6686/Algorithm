#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int arr[200001];

vector<int>v[200001];
int visited[200001];

int ans;

void dfs(int n) {
	for (int i = 0; i < v[n].size(); i++) {
		int k = v[n][i];
		if (visited[k] == 0) {
			visited[k] = 1;
			if (arr[k] == 0) {
				dfs(k);
			}
			else {
				ans++;
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
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		arr[i+1] = s[i] - '0';
	}

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] == 1) {
			visited[i] = 1;
			dfs(i);
			memset(visited, 0, sizeof(visited));
		}
	}
	cout << ans<<'\n';
}