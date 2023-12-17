#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;
int arr[300001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	long long int t = 1;
	long long int n=0;
	long long int m=0;
	for (int i = 0; i < N; i++) {
		n += (arr[i]) * (t - 1);
		m += arr[N-1-i] * (t-1);
		t *= 2;
		n %= MOD;
		m %= MOD;
		t %= MOD;
	}
	cout << ((n % MOD - m % MOD)+MOD) % MOD;
}