#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	while (getline(cin,s)) {
		int smallLetterCnt = 0;
		int bigLetterCnt = 0;
		int gapCnt = 0;
		int numCnt = 0;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 65 && s[i] <= 90) { // 대문자
				bigLetterCnt++;
			}
			else if (s[i] >= 97 && s[i] <= 122) { // 소문자
				smallLetterCnt++;
			}
			else if (s[i] == ' ') { // 공백
				gapCnt++;
			}
			else { // 숫자
				numCnt++;
			}
		}
		cout << smallLetterCnt << ' ' << bigLetterCnt << ' ' << numCnt << ' ' << gapCnt << '\n';
	}
	
}