#include <iostream>
#include <stack>
using namespace std;

stack<int>st[7];

int main() {
	int n, p;
	cin >> n >> p;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		while (!st[a].empty()) {
			int t = st[a].top();
			if (t < b) {
				st[a].push(b);
				ans++;
				break;
			}
			else if (t > b) {
				st[a].pop();
				ans++;
			}
			else {
				break;
			}
		}
		if (st[a].size()==0) {
			st[a].push(b);
			ans++;
		}		
	}
	cout << ans;
}