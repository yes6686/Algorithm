#include <iostream>
#include <string.h>
using namespace std;

int alpha[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.size(); j++) {
			alpha[s[j] - 'A'] = 1;
		}
		int sum = 0;
		for (int j = 0; j < 26; j++) {
			if (alpha[j] == 0) {
				sum += 65 + j;
			}
		}
		cout << sum << '\n';
		memset(alpha, 0, sizeof(alpha));
	}
}