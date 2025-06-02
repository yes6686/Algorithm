#include <iostream>
#include <vector>
using namespace std;

int arr[1001];
vector<int>v[1001];
int check[1001];

void dfs(int x) {
	if (check[x] == 1) return;
	check[x] = 1;
	dfs(v[x][0]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 0;i < n;i++) {
			cin >> arr[i];
			v[i + 1].push_back(arr[i]);
		}
		for (int i = 1;i <= n;i++) {
			if (check[i] == 0) {
				ans++;
				dfs(i);
			}
		}
		cout << ans << '\n';
		for (int i = 1;i <= n;i++) {
			v[i].clear();
			check[i] = 0;
		}
	}
}