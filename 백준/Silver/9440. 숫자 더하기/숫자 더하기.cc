#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[15];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		int zeroCnt = 0;
		string num = "";
		string zero = "";
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (arr[i] == 0) zero += '0';
		}
		sort(arr, arr + n);

		for (int i = 0; i < n; i++) {
			if (arr[i] == 0) continue;
			num += (arr[i] + '0');
		}
		num.insert(2, zero);

		int a = 0, b = 0;

		for (int i = 0; i < num.size(); i+=2) {
			a *= 10;
			a += (num[i] - '0');
		}
		for (int i = 1; i < num.size(); i += 2) {
			b *= 10;
			b += (num[i] - '0');
		}
		cout << a + b << '\n';
	}
}