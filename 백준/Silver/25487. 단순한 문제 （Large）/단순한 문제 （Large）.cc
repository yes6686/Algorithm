#include <iostream>
#include <algorithm> // Include this header for std::min
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int T;
	cin >> T;
	while (T--) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << min({ a,b,c }) << '\n';
	}
}