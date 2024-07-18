#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	string s1 = "KOREA";
	string s2 = "YONSEI";
	int k1 = 0;
	int k2 = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == s1[k1]) {
			k1++;
		}
		if (s[i] == s2[k2]) {
			k2++;
		}
		if (k1 == 5) {
			cout << s1;
			return 0;
		}
		else if (k2 == 6) {
			cout << s2;
			return 0;
		}
	}	
}