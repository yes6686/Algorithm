#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long int n;
	cin >> n;
	cout << (n * (n - 1)) / 2 << '\n';
	cout << 2 << '\n';
}