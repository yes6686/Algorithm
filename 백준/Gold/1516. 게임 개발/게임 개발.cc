#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int>v[100001];
queue<int>q;

int inDegree[100001];

int arr[501];
int dp[501];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int x;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
		while (1) {
			cin >> x;
			if (x == -1) {
				break;
			}
			else {
				v[x].push_back(i);
				inDegree[i]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int k = q.front();
		q.pop();
		for (int i = 0; i < v[k].size(); i++) {
			int j = v[k][i];
			inDegree[j]--;
			dp[j] = max(dp[j], arr[j] + dp[k]);
			if (inDegree[j] == 0) {
				q.push(j);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << dp[i] << '\n';
	}


}