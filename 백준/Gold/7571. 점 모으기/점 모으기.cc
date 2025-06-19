#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arrx[100001];
int arry[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		cin >> arrx[i] >> arry[i];
	}
	sort(arrx, arrx + m);
	sort(arry, arry + m);
	
	int mx = arrx[m / 2];
	int my = arry[m / 2];

	int ans = 0;
	for (int i = 0;i < m;i++) {
		ans += (abs(arrx[i] - mx) + abs(arry[i] - my));
	}
	cout << ans << '\n';
}

