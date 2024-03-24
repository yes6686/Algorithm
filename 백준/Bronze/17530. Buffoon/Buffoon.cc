#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int maxV = 0;
	int maxIndex = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (maxV < x) {
			maxV = x;
			maxIndex = i;
		}
	}
	if (maxIndex == 0) {
		cout << "S";
	}
	else {
		cout << "N";
	}
}