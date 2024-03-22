#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long int n;
	cin >> n;
	int cnt = 0;
	while (n!=1) {
		cnt++;
		if (n % 2 == 0){
			n/=2;
		}
		else {
			n += 1;
		}
	}
	cout << cnt;
}