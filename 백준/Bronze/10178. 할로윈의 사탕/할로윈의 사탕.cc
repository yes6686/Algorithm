#include <iostream>
using namespace std;

int main() {

	int T;
	cin >> T;
	int c, v;
	while (T--) {
		cin >> c >> v;
		cout << "You get " << c / v << " piece(s) and your dad gets " << c % v << " piece(s)." << endl;

		
	}
}