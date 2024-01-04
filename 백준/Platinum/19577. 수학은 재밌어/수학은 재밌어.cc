#include <iostream>
#include <set>
using namespace std;
set<int>s;
set<int>x;

int euler(int n) {
	int ans = n;
	for (int i = 2; i * i <= n; i++) {
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
	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) {
		ans *= (*iter - 1);
	}
	s.clear();
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int ans = n;
	int check = n;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			x.insert(i);
			if(ans/i!=i)
				x.insert(ans / i);
		}
	}
	set<int>::iterator iter;
	for (iter = x.begin(); iter != x.end(); iter++) {
		if ((*iter) * (euler(*iter)) == check) {
			cout << *iter << '\n';
			return 0;
		}
	}
	cout << -1;
}