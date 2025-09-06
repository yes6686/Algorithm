#include <iostream>
#include <string>
using namespace std;

int alpha[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0;i < n;i++) {
		string s;
		getline(cin, s);
		
		for (int j = 0;j < s.size();j++) {
			if (s[j] >= 'a' && s[j] <= 'z') {
				alpha[s[j] - 'a'] = 1;
			}
			else if(s[j] >= 'A' && s[j] <= 'Z'){
				alpha[s[j] - 'A'] = 1;
			}
		}

		int check = 1;
		string ans = "";
		for (int i = 0;i < 26;i++) {
			if (alpha[i] == 0) {
				check = 0;
				ans += ('a' + i);
			}
			alpha[i] = 0;
		}

		if (check == 1) cout << "pangram" << '\n';
		else {
			cout << "missing" << " " << ans << '\n';
		}
	}
}