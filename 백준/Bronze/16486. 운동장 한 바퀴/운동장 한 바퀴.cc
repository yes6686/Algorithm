#include <iostream>
using namespace std;

const double PI = 3.141592;

int main() {
	int d1,d2;
	cin >> d1 >> d2;
	double ans = 2 * d1 + PI * d2 *2;
	cout << fixed;
	cout.precision(7);	
	cout << ans;
}