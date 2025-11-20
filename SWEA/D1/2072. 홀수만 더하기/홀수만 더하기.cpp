#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int i = 1;i <= T;i++) {
		int ans = 0;
		for (int j = 0;j < 10;j++) {
			int x;
			cin >> x;
			if (x % 2 == 1) ans += x;
		}

		cout << "#" << i << " " << ans << '\n';
	}


}