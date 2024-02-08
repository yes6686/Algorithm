#include <iostream>
using namespace std;

int main() {
	double w,h;
	cin >> w >> h;
	double ans =  (w * h)/2;
	cout << fixed;
	cout.precision(1);
	cout << ans;
}