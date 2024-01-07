#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<string,int>m;
vector<string>v;

bool compare(string a, string b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	string n;
	for (int i = 0; i < a; i++) {
		cin >> n;
		m[n] = 1;
		
	}
	int cnt = 0;
	for (int i = 0; i < b; i++) {
		cin >> n;
		if (m[n] == 1) {
			cnt++;
			v.push_back(n);
		}
	}
	cout << cnt << '\n';
	sort(v.begin(), v.end(),compare);
	while (!v.empty()) {
		string n = v.back();
		v.pop_back();
		cout << n << '\n';
	}
	

}