#include <iostream>
#include <vector>
using namespace std;

vector<pair<string, int>>v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		int d;
		cin >> s >> d;
		v.push_back({ s,d });
	}
	for (int i = 0; i < m; i++) {
		int d;
		cin >> d;
		
		int s = 0;
		int e = n - 1;
		string str="";
		while (s <= e) {
			int m = (s + e) / 2;
			if (v[m].second >= d) {
				e = m - 1;
				str = v[m].first;
			}
			else {
				s = m + 1;
			}
		}
		cout << str << '\n';
		
	}
}