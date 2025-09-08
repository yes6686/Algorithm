#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		double x;
		cin >> x;

		cout << fixed;
		cout.precision(2);

		cout << "$" << x*0.8 << '\n';
	}

}