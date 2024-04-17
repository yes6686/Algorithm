#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		int k = m * 2 - n;
		cout << k << ' ' << m-k << '\n';
	}
}