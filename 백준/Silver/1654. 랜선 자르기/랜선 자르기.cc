#include <iostream>
#include <algorithm>
using namespace std;

long long int arr[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K, N;
	cin >> K >> N;

	long long int maxAns = 0;
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
		maxAns = max(maxAns, arr[i]);			
	}
	sort(arr, arr + K);
	long long int s = 1;
	long long int e = maxAns;
	while (s<=e) {
		long long int m = (s + e) / 2;
		long long int cnt = 0;
		for (int i = 0; i < K; i++) {
			cnt += arr[i] / m;
		}
		if (cnt >= N) {
			s = m + 1;
			maxAns = m;
		}
		else {
			e = m - 1;
		}
	}
	cout << maxAns << '\n';
}