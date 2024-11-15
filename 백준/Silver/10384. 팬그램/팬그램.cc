#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int alpha[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		for (int j = 0; j < s.size(); j++) {
			if (s[j] >= 'a' && s[j] <= 'z') {
				alpha[s[j] - 'a']++;
			}
			else if (s[j] >= 'A' && s[j] <= 'Z') {
				alpha[s[j] - 'A']++;
			}
		}
		int isTriple = 1;
		int isDouble = 1;
		int isPangran = 1;
		for (int i = 0; i < 26; i++) {
			if (alpha[i] < 3) {
				isTriple = 0;
			}
			if (alpha[i] < 2) {
				isDouble = 0;
			}
			if (alpha[i] < 1) {
				isPangran = 0;
			}
		}
		cout << "Case " << i + 1 << ": ";
		if (isTriple) cout << "Triple pangram!!!" << '\n';
		else if (isDouble) cout << "Double pangram!!" << '\n';
		else if (isPangran) cout << "Pangram!" << '\n';
		else {
			cout << "Not a pangram" << '\n';
		}
		memset(alpha, 0, sizeof(alpha));
	}
}