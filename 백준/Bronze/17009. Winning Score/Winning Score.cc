// 1
#include <iostream>
using namespace std;

int arr[3] = { 3,2,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int x;
	int bsum = 0;
	int asum = 0;
	for (int i = 0; i < 3; i++) {
		cin >> x;
		bsum += x * arr[i];
	}
	for (int i = 0; i < 3; i++) {
		cin >> x;
		asum += x * arr[i];
	}
	if (bsum > asum) {
		cout << "A";
	}
	else if (bsum < asum) {
		cout << "B";
	}
	else {
		cout << "T";
	}
}