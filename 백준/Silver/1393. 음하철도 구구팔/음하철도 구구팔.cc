#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int dis(int a, int b, int c, int d) {
	return ((a - c) * (a - c) + (b - d) * (b - d));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int xs, ys;
	cin >> xs >> ys;
	int xe, ye, dx, dy;
	cin >> xe >> ye >> dx >> dy;
	int m = gcd(dx, dy);
	dx /= m;
	dy /= m;
	
	int minV = dis(xs, ys, xe, ye);
	int ansX=xe, ansY=ye;
	while (true) {
		xe += dx;
		ye += dy;
		if (minV > dis(xs, ys, xe, ye)) {
			minV = dis(xs, ys, xe, ye);
			ansX = xe;
			ansY = ye;
		}
		else {
			break;
		}
	}
	cout << ansX << ' ' << ansY;
}