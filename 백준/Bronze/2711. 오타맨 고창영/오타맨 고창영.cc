#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d;
		string s;
		cin >> d >> s;
		for (int j = 0; j < s.size(); j++) {
			if (j == d - 1) continue;
			cout << s[j];
		}
		cout << '\n';
	}
}