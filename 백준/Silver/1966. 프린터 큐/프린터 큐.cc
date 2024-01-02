#include <iostream>
#include <queue>
using namespace std;
int main() {
	int cnt;
	int T;
	cin >> T;
	int n, m;
	int k;
	while (T--) {
		cnt = 0;
		cin >> n >> m;
		queue<pair<int, int>>q;
		priority_queue<int>pq;
		for (int j = 0; j < n; j++) {
			cin >> k;
			q.push({ j,k });
			pq.push(k);
		}
		while (!q.empty()) {
			int idx = q.front().first;
			int val = q.front().second;
			q.pop();
			if (pq.top() == val) {
				pq.pop();
				cnt++;
				if (idx == m) {
					cout << cnt << endl;
					break;
				}
			}
			else q.push({ idx,val });
		}
	}
}