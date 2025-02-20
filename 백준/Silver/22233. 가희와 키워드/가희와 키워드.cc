#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int>mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		mp[s] = 1;
	}


	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		string w = "";
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == ',') {
				if (mp.find(w) != mp.end()) {
					mp.erase(w);
				}
				w = "";
				continue;
			}
			w += s[j];
		}
		if (mp.find(w) != mp.end()) {
			mp.erase(w);
		}
		cout << mp.size() << '\n';
	}

}