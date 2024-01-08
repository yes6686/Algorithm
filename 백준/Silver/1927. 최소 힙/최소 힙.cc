#include <iostream>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>>q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x != 0) {
			q.push(x);
		}
		else {
			if (q.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << q.top() << '\n';
				q.pop();
			}
		}
	}
	
}