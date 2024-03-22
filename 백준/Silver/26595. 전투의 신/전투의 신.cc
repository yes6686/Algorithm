#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	long long int a, pa, b, pb;
	cin >> a >> pa >> b >> pb;

	long long int maxV = 0;
	long long int maxPa=0, maxPb=0;
	
	long long int ka = n / pa;
	long long int kb = (n - ka * pa) / pb;

	if (maxV < a * ka + b * kb) {
		maxV = a * ka + b * kb;
		maxPa = ka;
		maxPb = kb;
	}

	while (ka>0) {
		ka -= 1;
		kb = (n - ka * pa) / pb;
		if (maxV < a * ka + b * kb) {
			maxV = a * ka + b * kb;
			maxPa = ka;
			maxPb = kb;
		}
	}
	cout << maxPa << ' ' << maxPb;
}