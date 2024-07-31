#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	getline(cin, s);
	string f;
	getline(cin, f);
	if (s.size() < f.size()) {
		cout << 0;
		return 0;
	}
	int check = 1;
	int cnt = 0;
	for (int i = 0; i < s.size()-f.size() + 1; i++) {
		check = 1;
		for (int j = 0; j < f.size(); j++) {
			if (s[i + j] != f[j]) {
				check = 0;
				break;
			}
		}
		if (check == 1) {
			cnt++;
			i += (f.size() - 1);
		}
	}
	cout << cnt;
}