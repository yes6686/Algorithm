#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		int zeroCnt = 0;
		for (int i = n; i <= m; i++) {
			string s = to_string(i);
			for (int j = 0; j < s.size(); j++) {
				if (s[j] == '0') zeroCnt++;
			}
		}
		cout << zeroCnt << '\n';
	}
}