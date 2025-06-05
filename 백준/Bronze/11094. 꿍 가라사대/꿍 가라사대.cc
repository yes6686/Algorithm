#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cin.ignore();
	string s;
	for (int i = 0;i < n;i++) {
		getline(cin, s);
		if (s.length() < 10) continue;
		string sl = s.substr(0, 10);
		string sr = s.substr(10);
		if (sl == "Simon says") {
			cout << sr << '\n';
		}
	}
}