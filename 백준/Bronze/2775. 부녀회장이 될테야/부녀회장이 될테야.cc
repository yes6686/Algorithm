#include <iostream>
using namespace std;
int sum = 0;
int residents(int k, int n) {
	
	if (k == 0) {
		
			sum += n;
		
	}
	else {
		for (int i = 1; i <= n; i++) {
			residents(k - 1, i);
		}
	}
	return sum;
}

int main() {

	int T;
	int k, n;
	cin >> T;
	while (T--) {
		cin >> k >> n;
		cout<<residents(k, n)<<'\n';
		sum = 0; 
		
	}
}