#include <iostream>
using namespace std;


int main() {
	int sum = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			sum += (i + j);
		}
	}
	cout << sum;

}