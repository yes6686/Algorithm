#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	
	int k = 1;
	int ans = 0;
	while (1) {
		if (n == 0) break;
		if (n >= k) {
			n -= k;
			ans++;
			k++;
		}
		else {
			k = 1;
		}
	}
	cout << ans;
}