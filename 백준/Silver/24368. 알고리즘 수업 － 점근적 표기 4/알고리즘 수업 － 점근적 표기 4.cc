//2
#include <iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	double a2, a1, a0;
	cin >> a2 >> a1 >> a0;
	double c;
	cin >> c;
	double n0;
	cin >> n0;
	int check = 1;
	for (double i = n0; i <= 1000; i+=(0.01)) {
		double a = (i * i) * c;
		double b = a2 * (i * i) + a1 * (i)+a0;
		if (a<b) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	return 0;
	
}