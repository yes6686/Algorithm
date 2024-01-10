#include <iostream>
using namespace std;
long long int arr[101];
long long int recursion(int n) {
	if (arr[n] != 0) return arr[n];
	if (n <= 3) return arr[n]=1;
	else if (n <= 5) return arr[n]=2;
	else {
		return arr[n] = recursion(n - 5) + recursion(n - 1);
	}
}
int main() {
	int T,N;
	cin >> T;

	while (T--) {
		cin >> N;
		cout << recursion(N) << endl;
	}
}