#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int s = 0;
	int e = n-1;
	int cnt = 0;
	while (s < e) {
		if (arr[s] + arr[e] < m) {
			s++;
		}
		else {
			cnt++;
			s++;
			e--;
		}
	}
	cout << cnt;
	
}