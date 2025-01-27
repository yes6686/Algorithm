#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << ((n % 2 == 0) ? "cubelover" : "koosaga") << '\n';
	}
}