#include <iostream>
#include <algorithm>
using namespace std;

int arr[10000001];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int check = 0;
	int index;
	int x = gcd(arr[0], arr[1]);
	if (x == 1) {
		check = 1;
		index = 0;
		x = gcd(arr[1], arr[2]);
		for (int i = 3; i < n; i++) {
			x = gcd(x, arr[i]);
		}
	}
	else {
		int prev = x;
		for (int i = 2; i < n; i++) {
			x = gcd(x, arr[i]);
			if (x == 1 && check==0) {
				x = prev;
				check = 1;
				index = i;
			}
			prev = x;
		}
	}
	if (check == 1 && x != 1) {
		cout << x << ' ' << arr[index] << '\n';
		return 0;
	}
	for (int i = 0; i < n; i++) {
		arr[i] /= x;
	}
	int a = gcd(arr[0],arr[1]);
	int b = gcd(arr[1],arr[2]);
	int c = gcd(arr[2],arr[3]);
	int aCnt = 0, bCnt = 0, cCnt = 0;
	int aIndex = -1, bIndex = -1, cIndex = -1;
	int ans = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] % a == 0) {
			aCnt++;
		}
		else {
			aIndex = i;
		}
		if (arr[i] % b == 0) {
			bCnt++;
		}
		else {
			bIndex = i;
		}
		if (arr[i] % c == 0) {
			cCnt++;
		}
		else {
			cIndex = i;
		}
	}
	if (aCnt == n - 1) {
		cout << x * a << ' ' << arr[aIndex] * x;
	}
	else if (bCnt == n - 1) {
		cout << x * b << ' ' << arr[bIndex] * x;
	}
	else if (cCnt == n - 1) {
		cout << x * c << ' ' << arr[cIndex] * x;
	}
	else {
		cout << -1;
	}
}