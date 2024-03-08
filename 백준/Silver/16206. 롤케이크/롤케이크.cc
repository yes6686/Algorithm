#include <iostream>
#include <queue>
using namespace std;

priority_queue<int,vector<int>,greater<int>>pq1;
priority_queue<int,vector<int>,greater<int>>pq2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x % 10 == 0) {
			pq1.push(x);
		}
		else {
			pq2.push(x);
		}
	}
	int ans = 0;
	while (!pq1.empty()){
		int k = pq1.top();
		pq1.pop();

		k /= 10;

		if (k - 1 <= m) {
			ans += k;
			m -= (k - 1);
		}
		else {
			cout << ans + m << '\n';
			return 0;
		}
	}
	while (!pq2.empty()) {
		int k = pq2.top();
		pq2.pop();
		k /= 10;
		if (k  <= m) {
			ans += k;
			m -= k;
		}
		else {
			cout << ans + m << '\n';
			return 0;
		}
	}
	cout << ans;
}