#include <iostream>
using namespace std;
int main() {

	int T;
	cin >> T;
	string s;
	int cnt = 0;
	while (T--) {
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				cnt++;
			}
			else {
				if (cnt == 0) {
					cnt++;
					break;
				}
				else {
					cnt--;
				}
			}
		}
		
		if (cnt == 0) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
		cnt = 0;
	}
	
}