#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string x;
	cin >> x;
	int ans = 0;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == '0') {
			ans += 9;
		}
		else {
			ans += (x[i] - '0');
		}
	}
	cout << ans;
}