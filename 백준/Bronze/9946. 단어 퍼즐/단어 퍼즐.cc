#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int i = 1;

	while (1) {
		string a, b;
		cin >> a >> b;
		if (a == "END" && b == "END") break;

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		cout << "Case " << i++ << ": ";
		if (a == b) {
			cout << "same" << '\n';
		}
		else {
			cout << "different" << '\n';
		}
	}
}