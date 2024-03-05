#include <iostream>
using namespace std;
int arr[10];
int main() {
	int T; cin >> T;
	while (T--) {
		string s; cin >> s;
		for (int i = 0; i < s.size(); i++) {
			arr[s[i] - '0'] = 1;
		}
		int ans = 0;
		for (int i = 0; i < 10; i++) {
			if (arr[i] == 1) {
				arr[i] = 0;
				ans++;
			}
		}
		cout << ans << '\n';
	}
}