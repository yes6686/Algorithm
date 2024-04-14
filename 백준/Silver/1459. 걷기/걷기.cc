#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long int x, y, w, s;
	cin >> x >> y >> w >> s;
	long long int ans=0;
	if (w > s) {
		while (x > 0 && y > 0) {
			x -= 1;
			y -= 1;
			ans += s;
		}

		if (x % 2 == 1) {
			x -= 1;
			ans += w;
		}
		if (y % 2 == 1) {
			y -= 1;
			ans += w;
		}
		ans += x * s;
		ans += y * s;
		cout << ans;
	}
	else {
		if (2 * w > s) {
			while (x > 0 && y > 0) {
				x -= 1;
				y -= 1;
				ans += s;
			}
			ans += x * w;
			ans += y * w;
			cout << ans;
		}
		else {
			ans = x * w + y * w;
			cout << ans;
		}
	}
}