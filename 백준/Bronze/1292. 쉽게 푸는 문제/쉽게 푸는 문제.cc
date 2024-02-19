#include <iostream>
using namespace std;
int arr[1001];
int main() {
	int k = 1;
	int a, b;
	cin >> a >> b;
	int n=1;
	while (1) {
		if (n * (n + 1) > 2 * b) {
			break;
		}
		else {
			n++;
		}
	}
	int index = 1;
	for (int i = 1;i<=n; i++) {
		for (int j = 1; j <= i; j++) {
			arr[index] = i;
			index++;
		}	
	}
	int sum = 0;
	for (int i = a; i <= b; i++) {
		sum += arr[i];
	}
	cout << sum;

}