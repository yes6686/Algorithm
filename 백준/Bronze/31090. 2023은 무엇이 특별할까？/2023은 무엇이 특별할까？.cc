#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int x;
		cin >> x;
		int k = x % 100;
		if ((x+1) % k == 0) {
			cout << "Good"<<'\n';
		}
		else {
			cout << "Bye"<<'\n';
		}
	}
}