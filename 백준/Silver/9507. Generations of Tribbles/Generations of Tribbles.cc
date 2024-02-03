#include <iostream>
using namespace std;
long long int arr[68];
long long int koong(int n) {
	if (arr[n] != 0) return arr[n];
	if (n < 2) return arr[n] = 1;
	if (n == 2) return arr[n] = 2;
	if (n == 3) return arr[n] = 4;
	else {
		return arr[n] = koong(n - 1) + koong(n - 2)
			+ koong(n - 3) + koong(n - 4);
	}
}
int main()
{
	int T;
	cin >> T;
	int n;
	while (T--) {
		cin >> n;
		cout << koong(n) << endl;
	}
}