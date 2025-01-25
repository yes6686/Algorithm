#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int arr[200001];

vector<int>v[200001];
queue<int> q;
int visited[200001];

int ans;
int cnt;

void dfs(int s,int n) {


	for (int i = 0; i < v[n].size(); i++) {
		int k = v[n][i];
		if (visited[k] == 0) {
			visited[n] = 1;
			if (arr[k] == 0) {
				dfs(s,k);
			}
			else {
				cnt++;
				if(v[k].size()!=1) q.push(k);
			}
			if (s == n) {
				ans += (cnt + 1) * cnt;
				cnt = 0;
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
		arr[i + 1] = s[i] - '0';
	}

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] == 1) {
			q.push(i);
			break;
		}
	}

	while (!q.empty()) {
		int k = q.front();
		q.pop();
		dfs(k,k);
	}

	cout << ans << '\n';
}