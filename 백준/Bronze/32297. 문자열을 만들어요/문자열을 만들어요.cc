#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0;i < n - 3;i++) {
		if (s[i] == 'g' && s[i+1] == 'o' && s[i+2] == 'r' && s[i+3] == 'i') {
			cout << "YES" << '\n';
			return 0;
		}
	}
	cout << "NO" << '\n';
}