#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int ans = 0;
	while (cin >> n) {
		ans += n;
	}
	cout << ans << '\n';
}