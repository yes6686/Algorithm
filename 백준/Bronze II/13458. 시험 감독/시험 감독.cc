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
	int b, c;
	cin >> b >> c;
	long long int minAns = 0;
	for (int i = 0; i < n; i++) {
		arr[i] -= b;
		minAns += 1;
		if (arr[i] > 0) {
			minAns += arr[i] / c; 
			if (arr[i] % c != 0) {
				minAns += 1;
			}
		}	
	}
	cout << minAns;
}