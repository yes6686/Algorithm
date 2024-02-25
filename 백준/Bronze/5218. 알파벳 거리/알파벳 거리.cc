#include <iostream>
#include <algorithm>
using namespace std;

int arr[11];

int main() {
	int T; cin >> T;
	while (T--) {
		string a, b;
		cin >> a >> b;
		cout << "Distances: ";
		for (int i = 0; i < a.size(); i++) {
			int aa = a[i] - 'A' + 1;
			int bb = b[i] - 'A' + 1;
			if (a[i] <= b[i]) {
				cout << bb-aa << ' ';
			}
			else {
				cout << (bb + 26) - aa << ' ';
			}
		}
		cout << '\n';
	}
}