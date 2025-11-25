#include <iostream>
#include <queue>
using namespace std;

priority_queue<long long int,vector<long long int>,greater<long long int>>pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0;i < n;i++) {
			int x;
			cin >> x;
			pq.push(x);
		}
		
		long long int ans = 0;
		while (pq.size() > 1) {
			long long int k1 = pq.top();
			pq.pop();
			long long int k2 = pq.top();
			pq.pop();
			ans += (k1 + k2);
			pq.push(k1 + k2);
		}
		pq.pop();
		cout << ans << '\n';
	}
}