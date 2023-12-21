#include <iostream>
using namespace std;

int main() {

	int n,m;
	string s;
	cin >> n;
	cin >> m;
	cin >> s;
	int conCheck = 0;
	int nCnt = 0;
	int ansCount = 0;
	for (int i = 1; i < m-1; i++) {
		if (s[i] == 'O') {
			if (s[i - 1] == 'I' && s[i + 1] == 'I') {
				nCnt++;
				if (nCnt >= n) {
					ansCount++;
				}
			}
			else {
				nCnt = 0;
			}
		}
		else {
			if (s[i - 1] == 'I') {
				nCnt = 0;
			}
		}
	}
	cout << ansCount;
}