#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int e, f, c;
	cin >> e >> f >> c;
	e += f;
	int ans = 0;
	while (e >= c) {
		int k = e / c;
		ans += e / c;
		e = e % c;
		e += k;
	}
	cout << ans;
}