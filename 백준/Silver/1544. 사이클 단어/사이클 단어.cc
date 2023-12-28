#include <iostream>
#include <set>
#include <map>
using namespace std;

set<string>st;
map<string, int>mp;


int main() {
	int n;
	cin >> n;
	string s,nw;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int k = s.size();
		int check = 0;
		for (int t = 0; t < k; t++) {
			nw="";
			for (int j = t; j < k+t; j++) {
				nw += s[j];
			}
			if (mp[nw] == 0) {
				st.insert(nw);
			}
			else {
				check = 1;
			}
			s += s[t];
		}
		if (check == 0) {
			set<string>::iterator iter;
			for (iter = st.begin(); iter != st.end(); iter++) {
				mp[*iter] = 1;
			}
			st.clear();
			cnt++;
		}
	}
	cout << cnt;
}