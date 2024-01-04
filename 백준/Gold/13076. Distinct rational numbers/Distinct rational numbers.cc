#include <iostream>
#include <set>
using namespace std;
set<int>s;
int dp[100001];

int euler(int n) {
	if (n == 1) return 1;
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


int go(int n) {
	if (dp[n]) return dp[n];
	
	dp[n] = euler(n)+go(n-1);
	return dp[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	dp[1] = 1;
	while (T--) {
		int n;
		cin >> n;
		cout << go(n)+1 << '\n';
		
	}
}