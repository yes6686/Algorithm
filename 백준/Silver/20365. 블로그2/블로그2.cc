#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt1 = 0;
	int cnt2 = 0;
	int check = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'R' && check == 1) {
			cnt1++;
			check = 0;
		}
		if (s[i] == 'B' && check == 0) {
			check = 1;
		}
	}
	check = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'B' && check == 1) {
			cnt2++;
			check = 0;
		}
		if (s[i] == 'R' && check == 0) {
			check = 1;
		}
	}
	cout << min(cnt1, cnt2) + 1;
}