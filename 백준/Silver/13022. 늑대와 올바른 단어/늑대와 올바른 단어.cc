#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int isFault = 0;
	int wCnt = 0;
	int oCnt = 0;
	int lCnt = 0;
	int fCnt = 0;
	int check = 0;
	for (int i = 0; i < s.size(); i++) {

		if (s[i] == 'w') {
			if (oCnt != lCnt || lCnt != fCnt) {
				isFault = 1;
				break;
			}
			if (check == 0) {
				if (wCnt != oCnt || lCnt != fCnt || oCnt != lCnt) {
					isFault = 1;
					break;
				}
				check = 1;
			}

			wCnt++;
		}
		else if (s[i] == 'o') {
			if (lCnt != fCnt) {
				isFault = 1;
				break;
			}
			oCnt++;
			if (wCnt < oCnt) {
				isFault = 1;
				break;
			}

		}
		else if (s[i] == 'l') {
			if (wCnt != oCnt) {
				isFault = 1;
				break;
			}
			lCnt++;
			if (oCnt < lCnt) {
				isFault = 1;
				break;
			}
		}
		else if (s[i] == 'f') {
			if (wCnt != oCnt || oCnt != lCnt) {
				isFault = 1;
				break;
			}
			fCnt++;
			if (lCnt < fCnt) {
				isFault = 1;
				break;
			}
			check = 0;
		}
	}
	if (wCnt != oCnt || lCnt != fCnt || oCnt != lCnt) {
		isFault = 1;
	}

	if (isFault == 1) {
		cout << 0;
	}
	else {
		cout << 1;
	}
}