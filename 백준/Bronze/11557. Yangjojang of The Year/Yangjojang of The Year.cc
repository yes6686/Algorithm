#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int maxV = 0;
		string maxS;
		for (int i = 0; i < n; i++) {
			string s;
			int x;
			cin >> s >> x;
			if (maxV < x) {
				maxS = s;
				maxV = x;
			}
		}
		cout << maxS << '\n';
	}
}