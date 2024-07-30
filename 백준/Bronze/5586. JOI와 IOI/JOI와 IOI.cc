#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int jcnt = 0;
	int icnt = 0;
	for (int i = 0; i < s.size() - 2; i++) {
		if (s[i] == 'J' && s[i+1]=='O' && s[i + 2] == 'I') {
			jcnt++;
		}
		else if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I') {
			icnt++;
		}
	}
	cout << jcnt << '\n' << icnt;
}