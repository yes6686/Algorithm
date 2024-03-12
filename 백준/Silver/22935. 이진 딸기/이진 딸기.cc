//1
#include <iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		long long int x = 0;
		x = (x | n);
		x--;
		x %= 28;
		x++;
		if (x >= 16) x = 30 - x;
		for (int i = 8; i >=1; i /= 2) {


			if ((x & i) == i) {
				cout << "딸기";

			}
			else {
				cout << "V";
			}
		}
		cout << '\n';
	}
}