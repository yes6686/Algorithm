#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	double D, H, W;
	cin >> D >> H >> W;
	double m = 1;

	if (D * D > (H * m) * (H * m) + (W * m) * (W * m)) {
		while (D * D > (H * m) * (H * m) + (W * m) * (W * m)) {
			m += 0.0001;
		}
	}
	else if(D * D < (H * m) * (H * m) + (W * m) * (W * m)) {

		while (D * D < (H * m) * (H * m) + (W * m) * (W * m)) {
			m -= 0.0001;
		}
	}
	cout << int(H * m) << ' ' << int(W * m);
}