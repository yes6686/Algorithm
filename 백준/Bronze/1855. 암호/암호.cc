#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	string s;
	cin >> s;
	string ps = "";
	int check = 1;
	for (int i = 0; i < s.size(); i++) {
		if (i % n == 0) {
			check = (check == 1) ? 0 : 1;
		}
		if (check == 0) {
			ps += s[i];
		}
		else {
			int k = i / n;
			int h = i % n;
			ps += s[n*k+(n-h-1)];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < ps.size() / n; j++) {
			cout << ps[i + (n * j)];
		}
	}
}