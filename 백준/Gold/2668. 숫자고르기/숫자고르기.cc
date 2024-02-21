#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

int arr[101];
queue<int>q;
vector<int>ans;
int check[101];
int cnt[101];
int visited[101];

bool compare(int a, int b) {
	return a > b;
}

void dfs(int x) {
	if (visited[x] == 1) {
		while (!q.empty()) {
			ans.push_back(q.front());
			check[q.front()] = 1;
			q.pop();
		}
	}
	visited[x] = 1;
	cnt[arr[x]]++;
	if (cnt[arr[x]] == 2) {
		return;
	}
	q.push(x);
	dfs(arr[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == 0) {
			dfs(i);
			memset(visited, 0, sizeof(visited));
			memset(cnt, 0, sizeof(cnt));
			while (!q.empty()) q.pop();
		}
	}
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end(),compare);
	while (!ans.empty()) {
		cout << ans.back() << '\n';
		ans.pop_back();
	}
}