#include <iostream>
using namespace std;

int arrA[101];
int arrB[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arrB[i];
	}
	arrA[0] = arrB[0];
	cout << arrA[0] << ' ';
	for (int i = 1; i < n; i++) {
		int s = 0;
		for (int j = 0; j < i; j++) {
			s += arrA[j];
		}
		arrA[i] = (arrB[i] * (i+1)) - s;
		cout << arrA[i] << ' ';
	}
}