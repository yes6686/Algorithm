#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, string>M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		M[s] = to_string(i);
		M[to_string(i)] = s;
	}
	string x;
	for (int i = 1; i<= m; i++) {
		cin >> x;
		cout << M[x] << '\n';
	}
}