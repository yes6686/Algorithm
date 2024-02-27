#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		int x;
		cin >> x;
		for (int i = 1; i <= x; i+=2) {
			sum += i;
		}
		cout << sum << '\n';
	}	
}