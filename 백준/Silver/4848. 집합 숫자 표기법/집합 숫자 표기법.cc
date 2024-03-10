#include <iostream>
#include <map>
using namespace std;

string s[16];

map<string, int>mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	s[0] = "{}";
	mp[s[0]] = 0;
	for (int i = 1; i <= 15; i++) {
		s[i] = "{";
		for (int j = 0; j < i; j++) {
			if (j == i - 1) {
				s[i] += s[j];
			}
			else {
				s[i] += s[j];
				s[i] += ",";
			}
		}
		s[i] += "}";
		mp[s[i]] = i;
	}
	int T;
	cin >> T;
	while (T--) {
		string a, b;
		cin >> a >> b;
		cout << s[mp[a] + mp[b]] << '\n';
	}
}