#include <iostream>
#include <set>
using namespace std;

set<int>s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		n += 1;
		int ans = n;
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				ans /= i;
				s.insert(i);
			}
			while (n % i == 0) {
				n /= i;
			}
		}
		if (n > 1) {
			ans /= n;
			s.insert(n);
		}
		set<int>::iterator iter;

		for (iter = s.begin(); iter != s.end(); iter++) {
			ans *= (*iter - 1);
		}
		s.clear();
		cout << ans << '\n';
	}
}