#include <iostream>
using namespace std;


int main() {
	int n;
	cin >> n;	
	int a, b;
	cin >> a >> b;
	int cnt = 0;
	while (1) {
		if ( n==0 ||(a <= 1 && b <= 0)) break;
		if (a >= 2) {
			a -= 2;
		}
		else if (b >= 1) {
			b -= 1;
		}
		n--;
		cnt++;
	}
	cout << cnt;
}
