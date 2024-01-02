#include <iostream>

using namespace std;

int combination(int n, int k) {
	if (n == k || k == 0) return 1;
	else {
		return combination(n - 1, k) + combination(n - 1, k - 1);
	}

}

int main() {

	int n,k;
	cin >> n>>k;
	cout << combination(n, k);
	
}