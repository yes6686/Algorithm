#include <iostream>
using namespace std;

int cnt;

int recursion(string &s, int l, int r) {
	cnt++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int isPalindrome(string &s) {
	return recursion(s, 0, s.size() - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		cnt = 0;
		cout << isPalindrome(s)<<' '<<cnt<<'\n';
	}
}