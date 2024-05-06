#include <iostream>
using namespace std;

long long int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	while (n--) {
		long long int a, b;
		cin >> a >> b;
		cout << a * b / gcd(a, b) << '\n';
	}
}