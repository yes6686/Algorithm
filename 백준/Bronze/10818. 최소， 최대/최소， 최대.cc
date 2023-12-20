#include <iostream>
using namespace std;


int main() {
	

	int n,x;
	cin >> n;
	int min;
	int max;
	
	for (int i = 0; i < n; i++) {

		cin >> x;	
		if (i == 0) {
			min = x;
			max = x;
		}
		if (x < min) {
				min = x;
			}
		else if(x>max) {
				max = x;
			}
		}

	
	cout << min << ' ' << max;

}