#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s,k;
	cin >> s >> k;

	string ss="";
	for (int i = 0; i < s.size(); i++) {
		if ((s[i] >= 'a' && s[i] <= 'z')
			|| (s[i] >= 'A' && s[i] <= 'Z')) {
			ss += s[i];
		}
	}

	if (ss.find(k) != string::npos) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}