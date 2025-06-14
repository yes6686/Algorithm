#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l;
	cin >> n >> l;

	for (int i = 0;i < l-1;i++) {
		cout << 1;
	}
	cout << n;
}