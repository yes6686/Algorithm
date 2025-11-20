#include <iostream>
#include <string.h>
using namespace std;

int cnt[10];
int check[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int i = 1;i <= T;i++) {
		string s;
		cin >> s;

		int ch = 1;
		for (int j = 0;j < s.size();j++) {
			int k = s[j] - '0';
			cnt[k]++;
			if (cnt[k] > 2) {
				ch = 0;
				break;
			}
			else if (cnt[k] == 1) {
				if (check[j + k + 1]) {
					ch = 0;
					break;
				}
				check[j + k + 1] = k+1;
				if (j + k + 1 >= s.size()) {
					ch = 0;
					break;
				}
			}
			else {
				if (check[j] != k+1) {
					ch = 0;
					break;
				}
			}
		}
		if (ch == 1) {
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';
		}
		memset(check, 0, sizeof(check));
		memset(cnt, 0, sizeof(cnt));
	}


}