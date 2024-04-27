#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	long long int ans = 0;
	long long int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		long long int a, b;
		cin >> a >> b;
		ans += x * b + y * a;
		x = x + a;
		y = y + b;
	}
	cout << ans;
}