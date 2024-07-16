#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	string pstr;
	cin >> pstr;

	for (int i = 0; i < n; i++) {
		string filename;
		cin >> filename;
		string s = "";
		if (filename.size() < pstr.size()) {

			for (int j = 0; j < pstr.size(); j++) {
				if (pstr[j] != '*') s += pstr[j];
			}
			if (s == filename) {
				cout << "DA" << '\n';
			}
			else {
				cout << "NE" << '\n';
			}
			continue;
		}
		for (int j = 0; j < filename.size(); j++) {
			if (j<pstr.size() && pstr[j] == '*') {
				int t = filename.size() - pstr.size();
				s += '*';
				j += t;
			}
			else {
				s += filename[j];
			}
		}
		if (s == pstr) {
			cout << "DA" << '\n';
		}
		else {
			cout << "NE" << '\n';
		}
	}	
}