#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int n;
	cin >> n;

	int ans;
	int k = 1;
	for (int i = 1;i <= n;i++) {
		k *= 2;
		ans = (k + 1) * (k + 1);
	}

	cout << ans << '\n';
}