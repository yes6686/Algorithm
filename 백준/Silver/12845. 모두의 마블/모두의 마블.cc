#include <iostream>
using namespace std;

int arr[1001];

int main() {
	int n;
	cin >> n;
	int maxV = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		maxV = max(maxV, arr[i]);
		sum += arr[i];
	}
	cout << (sum - maxV) + (maxV * (n - 1));
}