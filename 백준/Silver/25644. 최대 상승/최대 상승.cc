#include <iostream>
using namespace std;

int arr[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ana = arr[0];
	int maxAns = 0;
	for (int i = 1; i < n; i++) {
		if (ana < arr[i]) {
			maxAns = max(maxAns, arr[i] - ana);
		}
		else {
			ana = arr[i];
		}
	}
	cout << maxAns;
}