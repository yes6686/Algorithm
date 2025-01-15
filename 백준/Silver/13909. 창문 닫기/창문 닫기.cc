#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	long long int k = 0;
	int ans = 0;
	int i = 1;
	while (true) {
		k = i * i;
		if (k > n) break;
		ans++;
		i++;
	}
	cout << ans << '\n';	
}