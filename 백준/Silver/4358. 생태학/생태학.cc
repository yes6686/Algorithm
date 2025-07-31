#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

map<string, int>mp;
set<string>st;
double cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	while (getline(cin,s)) {
		mp[s]++;
		cnt++;
		st.insert(s);
	}

	set<string>::iterator iter;

	cout << fixed;
	cout.precision(4);
	for (iter = st.begin();iter != st.end(); iter++) {
		cout << *iter << " " << (double)mp[*iter] /cnt *100 << '\n';
	}
}