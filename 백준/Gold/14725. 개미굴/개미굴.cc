#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


set<string>s;
string a;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		string k="";

		for (int i = 0; i < x; i++) {
			cin >> a;
			k += ("-" + a);
			s.insert(k);
		}
	}
	
	for (auto v : s) {
		int cnt = count(v.begin(), v.end(), '-');
		int p = v.find_last_of('-');
		string k = v.substr(p + 1, sizeof(v));
		for (int i = 0; i < cnt - 1; i++) {
			cout << "--";
		}
		cout << k << '\n';
	}


}