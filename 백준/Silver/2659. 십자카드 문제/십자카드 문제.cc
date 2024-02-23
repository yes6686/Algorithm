#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int>mp;

void go(int x) {
	string s = to_string(x);
	mp[s] = 1;
	for (int i = 0; i < 3; i++) {
		string k = "";
		for (int j = 1; j < s.size(); j++) {
			k += s[j];
		}
		k += s[0];
		mp[k] = 1;
		s = k;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s="";
	for (int i = 1; i <= 4; i++) {
		int x;
		cin >> x;
		s += to_string(x);
	}
	string kk=s;
	for (int i = 0; i < 3; i++) {
		string k = "";
		for (int j = 1; j < s.size(); j++) {
			k += s[j];
		}
		k += s[0];
		if (stoi(kk) > stoi(k)) {
			kk = k;
		}
		s = k;
	}
	s = kk;
	int cnt = 0;
	for (int i = 1111; i <= 9999; i++) {
		string c = to_string(i);
		int check = 0;
		for (int j = 0; j < c.size(); j++) {
			if (c[j] == '0') {
				check = 1;
				break;
			}
		}
		if (mp[to_string(i)] == 1 || check==1) continue;
		if (stoi(s) < i) break;
		go(i);
		cnt++;
	}
	cout << cnt;
}