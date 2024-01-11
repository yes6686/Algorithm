#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int arr[101];
set<int>s;
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int k;
	sort(arr, arr + n);
	if (n == 2) {
		k = arr[1]-arr[0];
	}
	else {
		k = gcd(arr[1] - arr[0], arr[2] - arr[1]);
		for (int i = 3; i < n; i++) {
			k = gcd(k, arr[i]-arr[i-1]);
		}
	}
	for (int i = 2; i*i <= k; i++) {
		if (k % i == 0) {
			s.insert(i);
			s.insert(k/i);
		}
	}
	s.insert(k);
	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << ' ';
	}
}