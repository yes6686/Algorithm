#include <iostream>
#include <math.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int x1, y1, r1;
	int x2, y2, r2;
	double distance;
	double radiusgap;


	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;


		distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

		radiusgap = r1 > r2 ? r1 - r2 : r2 - r1;

		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << -1 << endl;
		}
		else if ((r1 + r2 == distance) || (radiusgap == distance)) {
			cout << 1 << endl;
		}
		else if ((r1 + r2 > distance) && (radiusgap < distance)) {
			cout << 2 << endl;
		}
		else {
			cout << 0 << endl;
		}

	}

}