#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	long long int count = 0;
	for (long long int i = 1; i <= n - 2; i++) {
		count += i * (i + 1) / 2;
	}
	cout << count << '\n' << 3 << '\n';
}