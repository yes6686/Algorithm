#include <iostream>
#include <algorithm>
using namespace std;

long long int arr[100001];

void insertionSort(int a,int b) {
	int j;
	for (int i = a+1; i <= b; i++) {
		long long int k = arr[i];
		for (j = i - 1; j >= a; j--) {
			if (arr[j] <= k) break;
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = k;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < k; i++) {
		int l, r;
		long long x;
		cin >> l >> r >> x;
		for (int j = l-1; j < r; j++) {
			arr[j] += x;
		}
		if (x < 0) {
			insertionSort(0, r-1);
		}
		else {
			insertionSort(l - 1, n-1);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	
}