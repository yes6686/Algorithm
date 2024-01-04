#include <iostream>
#include <set>
using namespace std;
set<long long int>s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long int n;
	cin >> n;
	long long int ans = n;
	for (long long int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ans /= i;
			s.insert(i);
		}
		while (n % i == 0) {
			n /= i;
		}
	}
	if (n > 1) {
		ans /= n;
		s.insert(n);
	}
	set<long long int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) {
		ans *= (*iter-1);
	}
	cout << ans;
}