#include <iostream>
#include <string>
using namespace std;

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
			if (j == 0) {
				char c = toupper(s[j]);
				cout << c;
			}
			else {
				cout << s[j];
				
			}
		}
		cout << '\n';
	}
}