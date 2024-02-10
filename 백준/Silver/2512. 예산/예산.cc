#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		
	}
	int m;
	cin >> m; 
	
	sort(arr, arr + n);

	if (sum <= m) {
		cout << arr[n - 1]<<'\n';
		return 0;
	}	

	int s = 0;
	int e = arr[n-1];
	int ans=0;
	while (s <= e) {
		sum = 0;
		int mid = (s + e) / 2;
		for (int i = 0; i < n; i++) {
			if (arr[i] <= mid) {
				sum += arr[i];
			}
			else {
				sum += mid;
			}
		}
		if (sum > m) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
			ans = max(ans, mid);
		}
	}
	cout << ans;
}