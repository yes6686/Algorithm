#include <iostream>
#include <string>
using namespace std;

int slen;
string s;
int idx = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	slen = s.length();
	while (idx < slen) {
		cout << s[idx];
		idx += s[idx] - 'A' + 1;
	}
}