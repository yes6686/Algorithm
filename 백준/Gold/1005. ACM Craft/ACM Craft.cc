#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int>v[1001];
queue<int>q;
int arr[1001];
int dp[1001];
int len[1001];
int result[1001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int n, k;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			dp[i] = arr[i];

		}
		int x, y;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			v[x].push_back(y);
			len[y]++;
		}
		int w;
		cin >> w;
		for (int i = 1; i <= n; i++) {
			if (len[i] == 0) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			int k = q.front();
			q.pop();
			for (int i = 0; i < v[k].size(); i++) {
				int h = v[k][i];
				dp[h] = max(dp[h], arr[h] + dp[k]);
				len[h]--;
				if (len[h] == 0) {
					q.push(h);
				}
			}
		}
		cout << dp[w] << '\n';
		for (int i = 1; i <= n; i++) {
			dp[i] = 0;
			arr[i] = 0;
			v[i].clear();

		}

	}
}