#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	while (n>=2 && m>=2) {
		cnt++;
		n -= 2;
		m -= 2;
	}
	cout << cnt;
}