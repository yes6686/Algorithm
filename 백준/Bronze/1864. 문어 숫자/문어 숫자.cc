#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s = "-\\(@?>&%/";
	while (1) {
		string n;
		cin >> n;
		if (n == "#") break;
		
		int ans = 0;
		for (int i = 0 ; i < n.size() ; i++) {
			ans += (int)((s.find(n[i]) == 8) ? -1 : s.find(n[i]))* pow(8, n.size() - 1 - i);
		}
		cout << ans << '\n';
	}
}