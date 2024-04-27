#include <iostream>
using namespace std;

int arr[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int dm, dr;
	dm = arr[1] - arr[0];
	dr = arr[1] / arr[0];
	for (int i = 2; i < n; i++) {
		if (arr[i] - arr[i - 1] == dm && dm !=-1) {
			continue;
		}
		else {
			dm = -1;
		}
		if (arr[i] / arr[i - 1] == dr && dr !=-1) {
			continue;
		}
		else {
			dr = -1;
		}
	}
	if (dm != -1) {
		cout << arr[n - 1] + dm;
	}
	else {
		cout << arr[n - 1] * dr;
	}
}