#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long int ans = 0;
	int n;
	cin >> n;
	for (long long int i = 1; i < n; i++) {
		ans += (i * n) + i;
	}
	cout << ans;
}