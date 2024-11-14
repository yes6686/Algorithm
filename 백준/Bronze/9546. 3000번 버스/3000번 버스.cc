#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = (ans * 2 + 1);
		}
		cout << ans << '\n';
	}
}