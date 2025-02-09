#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	string kk = "1";
	int ans = 1;
	for (int i = 0; i < s.size(); i++) {

		while (true) {
			if (kk.find(s[i]) == string::npos) {
				kk = to_string(ans);
				int k = stoi(kk);
				k++;
				kk = to_string(k);
				ans++;
			}
			else {
				if (i == s.size() - 1) break;
				int idx = kk.find(s[i]);
				kk = kk.substr(idx + 1);
				break;
			}
		}
	}
	cout << ans << '\n';
}