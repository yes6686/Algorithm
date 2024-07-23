#include <iostream>
using namespace std;

int isPalin(string s) {
	for (int i = 0; i < s.size()/2; i++) {
		if (s[i] != s[s.size() - i - 1]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	int t = 0;
	string ss = s;
	while (true) {
		if (isPalin(ss) == 1) break;
		string k = "";
		for (int i = t; i >= 0; i--) {
			k += s[i];
		}
		ss = s;
		ss += k;
		t++;
	}
	cout << ss.size();
}