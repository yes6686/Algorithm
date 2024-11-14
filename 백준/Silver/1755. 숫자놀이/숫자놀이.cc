#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string alpha[10] = { "zero", "one","two","three","four",
"five","six","seven","eight","nine" };

pair<string,int> str[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	int k = 0;
	for (int i = n; i <= m; i++) {
		string s = to_string(i);
		str[k].first += alpha[s[0] - '0'];
		str[k].second += s[0] - '0';
		if (s.size() == 2) {
			str[k].first += ' ';
			str[k].first += alpha[s[1] - '0'];
			str[k].second *= 10;
			str[k].second += (s[1] - '0');
		}
		k++;
	}
	sort(str, str + k);
	for (int i = 1; i <= k; i++) {
		cout << str[i-1].second << ' ';
		if (i % 10 == 0) cout << '\n';
	}
}