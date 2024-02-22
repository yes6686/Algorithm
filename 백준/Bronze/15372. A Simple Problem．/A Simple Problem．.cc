#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		long long int n;
		long long int ans = 0;
		cin >> n;
		ans = n * n;
		cout << ans<<'\n';
	}
}