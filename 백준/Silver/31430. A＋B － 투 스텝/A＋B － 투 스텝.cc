#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	if (t == 1) {
		long long int a, b;
		cin >> a >> b;
		long long int k = a + b;
		string s = "aaaaaaaaaaaaa";
		for (int i = 0; i < s.size(); i++) {
			if (k) {
				s[i] = ((k%26) + 'a');
				k /= 26;
			}
			else {
				break;
			}
		}
		cout << s << '\n';
	}
	else {
		string s;
		cin >> s;
		long long int ans = 0;
		long long int r = 1;
		for (int i = 0; i < s.size(); i++) {
			ans += (s[i] - 'a') * r;
			r *= 26;
		}
		cout << ans << '\n';
	}
}