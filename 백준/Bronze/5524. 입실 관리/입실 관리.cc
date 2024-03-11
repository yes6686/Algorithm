#include <iostream>
//#include <string>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			cout << (char)tolower(s[j]);
		}
		cout << '\n';
	}
}