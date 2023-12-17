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
		n += arr[N-1-i] * t;
		m += (arr[i]) * t;
		t *= 2;
		n %= MOD;
		m %= MOD;
		t %= MOD;
	}
	cout << ((m % MOD - n % MOD)+MOD) % MOD;

}