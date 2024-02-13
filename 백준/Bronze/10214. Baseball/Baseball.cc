#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T;
	while (T--) {
		int YwinCnt = 0;
		int KwinCnt = 0;
		for (int i = 0; i < 9; i++) {
			int Y, K;
			cin >> Y >> K;
			YwinCnt+=Y;
			KwinCnt+=K;
		}
		if (YwinCnt == KwinCnt) cout << "Draw" << '\n';
		else if (YwinCnt > KwinCnt) cout << "Yonsei" << '\n';
		else cout << "Korea" << '\n';
	}
}