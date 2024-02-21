#include <iostream>
#include <string>
using namespace std;

bool isPrime(int x) {
	for (int i = 2; i*i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

bool isPalindrome(int x) {
	
	string s = to_string(x);

	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - i - 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	if (n == 1) {
		cout << 2;
		return 0;
	}
	while (1) {
		if (isPrime(n) && isPalindrome(n)) {
			cout << n << '\n';
			break;
		}
		else {
			n++;
		}
	}
	
}