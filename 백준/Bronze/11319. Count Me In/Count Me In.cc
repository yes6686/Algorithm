#include <iostream>
#include <string>
using namespace std;

char s1[10] = {'A','E','I','O','U','a','e','i','o','u'};

int main() {
	int n;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		string s;
		int cnt1 = 0;
		int cnt2 = 0;
		getline(cin, s);
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == ' ') {
				cnt1++;
				continue;
			}
			for (int t = 0; t < 10; t++) {
				if (s[j] == s1[t]) {
					cnt2++;
				}
			}
		}
		cout << s.length() - cnt1 - cnt2<< ' ' << cnt2 << '\n';
	}
}