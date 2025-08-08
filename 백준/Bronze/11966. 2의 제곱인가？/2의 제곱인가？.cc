#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	int check = 1;

	while (true) {
		if (n == 1) break;
        
		if (n % 2 == 0) {
			n /= 2;
		}
		else {
			check = 0;
			break;
		}
	}
	
	cout << check << '\n';
}
