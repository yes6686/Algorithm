#include <iostream>
#include <vector>
using namespace std;

vector<int>v[51];
vector<int>dis[51];

int arr[51];

void dfs(int n,int o) {

	for (int i = 0; i < v[n].size(); i++) {
		int k = v[n][i];
		if (k == o) continue;
		if (arr[k] == 0) {
			arr[k] = arr[n]+1;
			dfs(k,o);
		}
		else {
			if (arr[k] > arr[n]+1) {
				arr[k] = arr[n] + 1;
				dfs(k,o);
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		dfs(i,i);
		int maxC = 0;
		for (int j = 1; j <= n; j++) {
			maxC = max(maxC, arr[j]);
			arr[j] = 0;
		}
		dis[maxC].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		if (dis[i].size() != 0) {
			cout << i << ' ' << dis[i].size() << '\n';
			for (int j = 0; j < dis[i].size(); j++) {
				cout << dis[i][j] << ' ';
			}
			break;
		}
	}
}