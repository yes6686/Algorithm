#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double x1,x2, y1,y2, r1,r2;
	cin >> x1 >> y1 >> r1;
	cin >> x2 >> y2 >> r2;
	double centerDis = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
	double radiusSum = r1 + r2;
	
	if (centerDis >= radiusSum) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}
}