#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	int n;
	string initHorse;
	string goalHorse;
	int cntW = 0;
	int cntB = 0;
	int diffCnt = 0;
	int ans = 0;

	while (T--) {
		cntW = 0;
		cntB = 0;
		diffCnt = 0;
		ans = 0;
		cin >> n;
		cin >> initHorse;
		cin >> goalHorse;
		for (int i = 0; i < n; i++) {
			if (initHorse[i] != goalHorse[i]) {
				if (initHorse[i] == 'W') {
					cntW++;
				}
				else {
					cntB++;
				}
				diffCnt++;
			}
		}
		while (1) {
			if (cntW == 0 || cntB == 0) break;
			cntW--;
			cntB--;
			ans++;
		}
		ans += cntW + cntB;
		cout << ans<<'\n';
	}
}