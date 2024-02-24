#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>>bag;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>jewel;
priority_queue<pair<int, int>>q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v;
		jewel.push({ m,v });
	}
	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		bag.push(c);
	}
	long long ans = 0;
	while (!bag.empty()) {
		int k = bag.top();
		bag.pop();
		while (!jewel.empty()) {
			int mm = jewel.top().first;
			int vv = jewel.top().second;
			if (k >= mm) {
				q.push({ vv,mm });
				jewel.pop();
			}
			else {
				break;
			}
		}
		if (q.size() == 0) continue;
		ans += q.top().first;
		q.pop();
	}
	cout << ans;	
}