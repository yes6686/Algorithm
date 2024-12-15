#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int fs = 0;
		for (int j = 0; j < 3; j++) {
			fs += ((s[j] - 'A') * pow(26, 2-j));
		}
		int bs;
		string ss = "";
		for (int j = 4; j < s.size(); j++) {
			ss += s[j];
		}
		bs = stoi(ss);
		if (abs(fs - bs) <= 100) {
			cout << "nice" << '\n';
		}
		else {
			cout << "not nice" << '\n';
		}
	}
}