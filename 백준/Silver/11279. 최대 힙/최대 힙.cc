#include <iostream>
#include <queue>
using namespace std;

priority_queue<int>pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	int x;
	while (T--) {
		cin >> x;
		if (x == 0) {
			if (pq.size() == 0) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else if (x > 0) {
			pq.push(x);

		}
	}
}