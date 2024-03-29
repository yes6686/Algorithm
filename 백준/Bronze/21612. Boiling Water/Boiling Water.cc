#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int p = 5 * n - 400;
	cout << p << '\n';
	if (p < 100) {
		cout << 1;
	}
	else if(p>100){
		cout << -1;
	}
	else {
		cout << 0;
	}
}
