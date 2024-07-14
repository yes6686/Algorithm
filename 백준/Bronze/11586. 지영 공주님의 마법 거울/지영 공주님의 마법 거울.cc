#include <iostream>
using namespace std;

string s[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int k;
	cin >> k;
	switch (k)
	{
	case 1:
		for (int i = 0; i < n; i++) {
			cout << s[i] << '\n';
		}
		break;

	case 2:
		for (int i = 0; i < n; i++) {
			for (int j = n-1; j >=0; j--) {
				cout << s[i][j];
			}
			cout << '\n';
		}
		break;

	case 3:
		for (int i = n-1; i >= 0; i--) {
			cout << s[i] << '\n';
		}
		break;

	default:
		break;
	}
}