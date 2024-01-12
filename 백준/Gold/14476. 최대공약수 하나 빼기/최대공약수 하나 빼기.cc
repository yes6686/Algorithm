#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];
int larr[1000001];
int rarr[1000001];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	larr[0] = arr[0];
	rarr[n - 1] = arr[n - 1];
	for (int i = 1; i < n-1; i++) {
		larr[i] = gcd(larr[i-1], arr[i]);
	}
	for (int i = n - 2; i >= 1; i--) {
		rarr[i] = gcd(rarr[i+1], arr[i]);
	}
	int k=-1;
	int maxGcd = -1;

	if (arr[0] % rarr[1]) {
		maxGcd = rarr[1];
		k = arr[0];
	}
	if (arr[n - 1] % larr[n - 2]) {
		if (maxGcd < larr[n - 2]) {
			maxGcd = larr[n - 2];
			k = arr[n - 1];
		}
	}
	
	for (int i = 1; i < n - 2; i++) {
		int x = gcd(larr[i - 1], rarr[i + 1]);
		if (arr[i] % x) {
			if (maxGcd < x) {
				maxGcd = x;
				k = arr[i];
			}
		}
	}
	if (k == -1) {
		cout << -1;
	}
	else {
		cout << maxGcd << ' ' << k;
	}	
}