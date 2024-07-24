#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	double n, l, w, h;
	cin >> n >> l >> w >> h;

	double s = 0;
	double e = min(min(l, w),h);
	double ans = -1;
	int cnt = 0;
	while (s < e) {
		double mid = (s + e) / 2;
		long long int a = floor(l / mid) * floor(w / mid) * floor(h / mid);
		if (n <= a) {
			ans = mid;
			s = mid;
		}
		else if(n>a){
			e = mid;
		}
		cnt++;
		if (cnt >= 100) {
			break;
		}
	}
	cout << fixed;
	cout.precision(10);
	cout << ans;
}