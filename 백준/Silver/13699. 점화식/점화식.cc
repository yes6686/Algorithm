#include <iostream>
using namespace std;
long long int t[36];

int main() {
	int n;
	cin >> n;
	t[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			t[i] += t[j - 1] * t[i - j];
		}
	}
	cout << t[n];
}