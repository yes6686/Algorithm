#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	int zeroCnt = 0;
	int oneCnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			zeroCnt++;
		}
		else {
			oneCnt++;
		}
	}
	zeroCnt /= 2;
	oneCnt /= 2;

	string ans = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			if (oneCnt) {
				oneCnt--;
				continue;
			}
		}
		ans += s[i];
	}
	s = ans;
	ans = "";
	for (int i = s.size()-1; i >= 0; i--) {
		if (s[i] == '0') {
			if (zeroCnt) {
				zeroCnt--;
				continue;
			}
		}
		ans += s[i];
	}

	reverse(ans.begin(), ans.end());
	cout<<ans;
}