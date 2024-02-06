#include <iostream>

using namespace std;

int main() {
	int a[100000];
	int n;
	cin >> n;
	int r;
	int min=1000000;
	int max=0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (max < a[i]) {
			max = a[i];
		}
		if (min > a[i]) {
			min = a[i];
		}
	}
	if (n == 1) {
		cout << a[0] * a[0] << endl;
	}
	else {
		cout << max * min << endl;
	}
	
}