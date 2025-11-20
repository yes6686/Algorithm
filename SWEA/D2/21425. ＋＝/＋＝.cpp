#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int i = 1;i <= T;i++) {	
		int a, b, n;
		cin >> a >> b >> n;

		int cnt = 0;

		while (true) {
			if (a > b) {
				b += a;
				cnt++;
				if (b > n) {
					cout << cnt << '\n';
					break;
				}
			}
			else {
				a += b;
				cnt++;
				if (a > n) {
					cout << cnt << '\n';
					break;
				}
			}
		}
		
	}
}