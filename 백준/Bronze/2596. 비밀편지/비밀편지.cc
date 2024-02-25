#include <iostream>
using namespace std;

string ah[9];

int main() {

	ah[0] = "000000";
	ah[1] = "001111";
	ah[2] = "010011";
	ah[3] = "011100";
	ah[4] = "100110";
	ah[5] = "101001";
	ah[6] = "110101";
	ah[7] = "111010";

	int n;
	cin >> n;
	string s;
	cin >> s;

	string ans = "";
	for (int i = 0; i < n; i++) {
		string k = "";
		for (int j = 0+(6*i); j < 6+ (6 * i); j++) {
			k += s[j];
		}
		int check = 0;
		for (int j = 0; j < 8; j++) {
			int diffCnt = 0;
			for (int t = 0; t < 6; t++) {
				if (ah[j][t] != k[t]) {
					diffCnt++;
				}
			}
			if (diffCnt <= 1) {
				char a = j + 'A';
				ans += a;
				check = 1;
				break;
			}
		}
		if (check == 0) {
			cout << i + 1;
			return 0;
		}
	}
	cout << ans;
}