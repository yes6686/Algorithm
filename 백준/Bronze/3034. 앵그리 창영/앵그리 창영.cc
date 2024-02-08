#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, w, h;
	cin >> n >> w >> h;
	double k = sqrt(w * w + h * h);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (k >= x) {
			cout << "DA"<<'\n';
		}
		else {
			cout << "NE" << '\n';
		}
	}
}