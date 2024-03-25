#include <iostream>
#include <set>
using namespace std;
set<string>ss;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	
	for (int i = 0; i < s.size(); i++) {
		string k = "";
		for (int j = i; j < s.size(); j++) {
			k += s[j];
			ss.insert(k);
		}
	}
	cout << ss.size();
}
