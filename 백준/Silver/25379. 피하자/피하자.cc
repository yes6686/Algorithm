//1
#include <iostream>
using namespace std;

int arr[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	long long int k = 0;
	long long int a = 0;
	long long int minAns ;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 1) {
			k++;
		}
		else {
			a += k;
		}
	}
	minAns = a;
	k = 0;
	a = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] % 2 == 1) {
			k++;
		}
		else {
			a += k;
		}
	}
	cout << min(minAns, a);
}