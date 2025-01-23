#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int arr[200001];


int combination(int n, int r) {
	if (n == r || r == 0) {
		return 1;
	}
	else {
		return combination(n - 1, r - 1) + combination(n - 1, r);
	}
}

vector<int>v[200001];
vector<int>rv[200001];
int visited[200001];

int ans;
int cnt = 0;

void go(int n) {
	for (int i = 0; i < v[n].size(); i++) {
		int k = v[n][i];
		if (visited[k] == 0) {
			visited[k] = 1;
			rv[n].push_back(k);
			go(k);
		}
	}
}

void dfs(int n) {
	for (int i = 0; i < rv[n].size(); i++) {
		int k = rv[n][i];
		if (visited[k] == 0) {
			visited[k] = 1;
			if (arr[k] == 0) {
				dfs(k);
			}
			else {
				cnt++;
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
	visited[1] = 1;
	go(1);

	for (int i = 1; i <= n; i++) {
		if (arr[i] == 1) {
			cnt = 0;
			memset(visited, 0, sizeof(visited));
			visited[i] = 1;
			dfs(i);
			if (cnt == 0) continue;
			ans += combination(cnt + 1, 2)*2;
		}
	}
	cout << ans<<'\n';

}