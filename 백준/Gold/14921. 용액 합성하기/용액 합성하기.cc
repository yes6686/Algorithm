#include <iostream>
#include <cmath>
using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (arr[0] >= 0) {
		cout << arr[0] + arr[1] << '\n';
	}
	else {
		int s = 0;
		int e = n-1;
		int minAns = 2e9;
		while (s < e) {
			if (abs(minAns) > abs(arr[s] + arr[e])) {
				minAns = arr[s] + arr[e];
			}
			int k = e - 1;
			if (abs(arr[s] + arr[e]) < abs(arr[s] + arr[k])) {
				s++;
			}
			else {
				e--;
			}
		}
		cout << minAns;
	}
}