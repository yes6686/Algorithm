#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		cout << x + y << '\n';
	}
}