#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;

	while (T--) {
		int d;
		cin >> d;
		int t = 0;
		while (t * t+t <= d) {
			t++;
		}
		cout << t-1 << '\n';
	}
}