#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;

	string str = "";
	while (cin >> s) {
		str += s;
	}

	int ans = 0;
	s = "";
	for (int i = 0;i < str.size();i++) {
		if (str[i] == ',') {
			ans += stoi(s);
			s = "";
		}
		else {
			s += str[i];
		}
	}

	ans += stoi(s);
	cout << ans << '\n';
}