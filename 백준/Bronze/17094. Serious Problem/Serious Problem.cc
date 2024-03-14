#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt2 = 0;
	int cntE = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '2') {
			cnt2++;
		}
		else {
			cntE++;
		}
	}
	if (cnt2 > cntE) {
		cout << 2;
	}
	else if (cnt2 < cntE) {
		cout << "e";
	}
	else {
		cout << "yee";
	}
}