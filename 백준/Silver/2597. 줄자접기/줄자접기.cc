#include <iostream>
#include <algorithm>
using namespace std;

double r[2];
double b[2];
double y[2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	double n;
	cin >> n;
	cin >> r[0] >> r[1];
	cin >> b[0] >> b[1];
	cin >> y[0] >> y[1];

	sort(r, r + 2);
	sort(b, b + 2);
	sort(y, y + 2);

	double mr = (r[1] + r[0]) / 2;
	for (int i = 0; i < 2; i++) {
		if (b[i] < mr) {
			b[i] += (mr - b[i]) * 2;
		}
		b[i] -= mr;
		if (y[i] < mr) {
			y[i] += (mr - y[i]) * 2;
		}
		y[i] -= mr;
	}
	if (n / 2 > mr) {
		n -= mr;
	}
	else {
		n = mr;
	}
	
	if (b[1] != b[0]) {
		double mb = (b[1] + b[0]) / 2;
		for (int i = 0; i < 2; i++) {
			if (y[i] < mb) {
				y[i] += (mb - y[i]) * 2;
			}
			y[i] -= mb;
		}
		if (n / 2 > mb) {
			n -= mb;
		}
		else {
			n = mb;
		}
	}
	if (y[1] != y[0]) {
		double my = (y[1] + y[0]) / 2;

		if (n / 2 > my) {
			n -= my;
		}
		else {
			n = my;
		}
	}
	cout << fixed;
	cout.precision(1);
	cout << n << '\n';
}