// 2번
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

string s[200001];

map<pair<string,string>,string>mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		string k = s;
		string se = "";
		se += s[0];
		se += s[s.size() - 1];
		sort(k.begin(), k.end());
		mp[{se,k}] = s;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		string k = s;
		string se = "";
		se += s[0];
		se += s[s.size() - 1];
		sort(k.begin(), k.end());
		cout << mp[{se, k}] << ' ';

	}
}