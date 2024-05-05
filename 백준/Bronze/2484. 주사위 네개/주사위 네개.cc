#include <iostream>
#include <algorithm>
using namespace std;

int arr[7];

int main() {
	int n;
	cin >> n;
	int maxAns = 0;
	while (n--) {
		int p = 0;
		for (int i = 0; i < 4; i++) {
			int x;
			cin >> x;
			arr[x]++;
		}
		int cnt = 0;
		for (int i = 1; i <= 6; i++) {
			if (arr[i]) cnt++;
		}
		if (cnt == 1) {
			for (int i = 1; i <= 6; i++) {
				if (arr[i]) p += 50000 + i * 5000;
			}
		}
		else if (cnt == 2) {
			for (int i = 1; i <= 6; i++) {
				if (arr[i] == 3) {
					p += 10000 + i * 1000;
				}
			}
			int tc = 0;
			for (int i = 1; i <= 6; i++) {
				if (arr[i] == 2) {
					tc = 1;
					p += i * 500;
				}
			}
			if (tc == 1) {
				p += 2000;
			}
		}
		else if (cnt == 3) {
			for (int i = 1; i <= 6; i++) {
				if (arr[i] == 2) {
					p += 1000 + i * 100;
				}
			}
		}
		else {
			for (int i = 6; i >= 1; i--) {
				if (arr[i]) {
					p += i * 100;
					break;
				}
			}
		}
		for (int i = 1; i <= 6; i++) {
			arr[i] = 0;
		}
		maxAns = max(maxAns, p);
	}
	cout << maxAns;
}