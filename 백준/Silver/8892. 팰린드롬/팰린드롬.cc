#include <iostream>
using namespace std;

int isPalindrome(string s) {

	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - i - 1]) {
			return 0;
		}
	}

	return 1;
}

string str[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> str[i];
		}
		int check = 0;
		for (int i = 0; i < n - 1; i++) {
			if (check) break;
			for (int j = i + 1; j < n; j++) {
				string s1 = str[i] + str[j];
				string s2 = str[j] + str[i];
				if (isPalindrome(s1) == 1) {
					cout << s1 << '\n';
					check = 1;
					break;
				}
				else if (isPalindrome(s2) == 1) {
					cout << s2 << '\n';
					check = 1;
					break;
				}
			}
		}
		if (check == 0) {
			cout << 0 << '\n';
		}
	}	
}