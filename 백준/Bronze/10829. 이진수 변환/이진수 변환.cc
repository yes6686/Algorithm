#include <iostream>
using namespace std;

int check = 0;

void solve(long long int n) {

	if (n == 0) return;
	solve(n / 2);
	if (n % 2 == 1) check = 1;
	if(check==1) cout << n % 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long int n;
	cin >> n;
	solve(n);
}
