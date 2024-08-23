#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 1; i <= s.size(); i++) {
		if (s[i-1] == 'N') continue;
		cnt++;
		for (int j = i; j <= s.size(); j+=i) {
			(s[j - 1] == 'N') ? (s[j-1] = 'Y') : (s[j - 1] = 'N');
		}
	}
	cout << cnt;
}