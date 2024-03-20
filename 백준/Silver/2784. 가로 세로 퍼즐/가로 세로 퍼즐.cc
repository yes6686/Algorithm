#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

string s[6];
map<string, int>mp;
int ex = 0;

void dfs(int d,string k) {
	if (ex == 1) return;
	if (d == 3) {
		string ch[3];
		int t = 0;
		string kk = "";
		map<string, int>cmp;
		for (int i = 0; i < k.size(); i++) {
			if (k[i] == ',') {
				ch[t] = kk;
				kk = "";
				t++;
			}
			else {
				kk += k[i];
			}
		}
		string cc = "";
		for (int i = 0; i < 3; i++) {
			cmp[ch[i]]++;
			cc = "";
			for (int j = 0; j < 3; j++) {
				cc += ch[j][i];
			}
			cmp[cc]++;		
		}
		int check = 1;
		for (int i = 0; i < 6; i++) {
			if (mp[s[i]]!=cmp[s[i]]) {
				check = 0;
				break;
			}
		}
		if (check == 1) {
			ex = 1;
			for (int i = 0; i < 3; i++) {
				cout << ch[i] << '\n';
			}
		}
		cmp.clear();
		return;
	}


	for (int i = 0; i < 6; i++) {
		dfs(d+1, k + s[i] + ",");
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 6; i++) {
		cin >> s[i];
		mp[s[i]]++;
	}
	//sort(s, s + 6);
		
	dfs(0, "");

	if (ex == 0) {
		cout << 0;
	}
}