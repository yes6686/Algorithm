#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int arr[9];
int n, m;
int c[10001];
int r[9];
vector<int>v[10001];
void dfs(int depth,int x) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';

		return;
	}
	
	/*for (int i = 1; i <= n; i++) {
		if (c[i]==0) {
			c[i] = 1;
			arr[depth] = r[i];
			dfs(depth + 1);
			c[i] = 0;
		}
	}*/
	for (int i = 0; i < v[x].size(); i++) {
		//if (c[v[x][i]] == 0) {
			//c[v[x][i]] = 1;
			int k = v[x][i];
			arr[depth] = k;
			dfs(depth + 1, k);
			//c[v[x][i]] = 0;
		//}
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> r[i];
	}
	sort(r, r + n+1);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			v[r[i]].push_back(r[j]);
		}
	}
	dfs(0,r[1]);
	
}

	
