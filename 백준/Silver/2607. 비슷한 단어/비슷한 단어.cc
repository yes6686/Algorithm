#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int alpha1[27];
int alpha2[27];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		alpha1[str[i] - 'A']++;
	}

	int ans = 0;

	for (int i = 0; i < n - 1; i++) {
		string s;
		cin >> s;

		for (int i = 0; i < s.size(); i++) {
			alpha2[s[i] - 'A']++;
		}

		int check = 1;
		int cnt1 = 0;
		int cnt2 = 0;
		for (int i = 0; i < 26; i++) {
			if (abs(alpha1[i] - alpha2[i]) >= 2) {
				check = 0;
				break;
			}
			if (alpha1[i] > alpha2[i]) {
				cnt1 += 1;
			}
			else if(alpha1[i] < alpha2[i]) {
				cnt2 += 1;
			}
			if (cnt1 >= 2 || cnt2 >= 2) {
				check = 0;
				break;
			}
		}
		if (check == 1) {
			ans++;
		}
		memset(alpha2, 0, sizeof(alpha2));
	}

	cout << ans << '\n';

}