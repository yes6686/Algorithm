#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s[301];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		sort(s[i].begin(), s[i].end());
	}
	sort(s, s + n);
	string ss = "";
	for (int i = 0; i < k; i++) {
		ss += s[i];
	}
	sort(ss.begin(), ss.end());
	cout << ss;
}