#include <iostream>
using namespace std;

int main() {

	for (int i = 0; i < 3; i++) {
		string s;
		cin >> s;
		int maxAns = 1;
		for (int t = 0; t <= 9; t++) {
			int cnt = 0;
			for (int j = 0; j < s.size(); j++) {
				if (s[j] - '0' == t) {
					cnt++;
					maxAns = max(maxAns, cnt);
				}
				else {
					maxAns = max(maxAns, cnt);
					cnt = 0;
				}
			}
		}
		cout << maxAns << '\n';
	}
}