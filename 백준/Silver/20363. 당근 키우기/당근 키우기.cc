#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    
	int x, y;
	cin >> x >> y;
	int ans = 0;
	if (x > y) {
		ans = x + y / 10 + y;
	}
	else {
		ans = y + x / 10 + x;
	}
	cout << ans;
}