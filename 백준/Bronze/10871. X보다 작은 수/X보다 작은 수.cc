#include <iostream>
using namespace std;



int main() {
	
	int a[10001];

	int n, x;
	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] < x) {
			cout << a[i] << ' ';
		}
	}



}