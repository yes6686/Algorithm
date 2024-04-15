#include <iostream>
using namespace std;

double arr[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, l;
	cin >> n >>l;
	double al = 0;
	int c = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		al += arr[i];
		if (i >= l) {
			al -= arr[i - l];
		}
		if (al >= 129 && al <= 138) {
			c++;
		}
	}
	cout << c;
}