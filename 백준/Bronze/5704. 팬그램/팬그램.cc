#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		string s;
		getline(cin, s);
		if (s == "*") break;
		int arr[26];
		for (int i = 0; i < 26; i++) {
			arr[i] = 0;
		}
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] < 97 || s[i]>122) continue;
			if (arr[s[i] - 'a'] == 0) {
				arr[s[i] - 'a'] = 1;
				cnt++;
			}
		}
		if (cnt == 26) {
			cout << "Y" << '\n';
		}
		else {
			cout << "N" << '\n';
		}
	}
}