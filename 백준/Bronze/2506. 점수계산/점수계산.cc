#include <iostream>
using namespace std;
int main() {
	int arr[101];
	int n;
	int sum = 0;
	int cnt = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] == 1) {
			sum += cnt;
			cnt++;
		}
		else {
			cnt = 1;
		}
	}
	cout << sum;

}