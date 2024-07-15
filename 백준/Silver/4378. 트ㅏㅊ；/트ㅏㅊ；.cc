#include <iostream>
#include <string>
using namespace std;

string str[4] = { "`1234567890-=","QWERTYUIOP[]\\","ASDFGHJKL;\'","ZXCVBNM,./" };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	while (getline(cin, s)) {
		for (int t = 0; t < s.size(); t++) {
			if (s[t] == ' ') {
				cout << s[t];
				continue;
			}
			int check = 0;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < str[i].size(); j++) {
					if (s[t] == str[i][j]) {
						cout << str[i][j - 1];
						check = 1;
						break;
					}
				}
				if (check) break;
			}
		}
		cout << '\n';
	}

}