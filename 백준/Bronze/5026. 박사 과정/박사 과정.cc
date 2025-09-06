#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;

		if (s == "P=NP") {
			cout << "skipped" << '\n';
			continue;
		}
		int ans = 0;
		string k = "";
		for (int j = 0;j < s.size();j++) {
			if(s[j]=='+') {
				ans += stoi(k);
				k = "";
			}
			else {
				k += s[j];
			}
		}
		ans += stoi(k);
		cout << ans << '\n';
	}
}