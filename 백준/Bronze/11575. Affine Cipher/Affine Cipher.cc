#include <iostream>
#define MOD 26
using namespace std;

int e(int a,int b, int x) {
	return (a * x + b) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			int al = e(a, b, s[i] - 'A');
			char c = al + 'A';
			cout << c;
		}
		cout << '\n';
	}
}