#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n; cin >> n;
		int maxV = -1000000;
		int minV = 1000000;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			maxV = max(maxV, x);
			minV = min(minV, x);
		}
		cout << minV << ' ' << maxV << '\n';
	}	
}