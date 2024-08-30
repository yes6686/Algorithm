#include <iostream>
#include <algorithm>
using namespace std;

string s[301];
char str[90001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s, s + n);
	string ss = "";
	for (int i = 0; i < k; i++) {
		ss += s[i];
	}
	for (int i = 0; i < ss.size(); i++) {
		str[i] = ss[i];
	}

	sort(str, str + ss.size());
	cout << str;
}