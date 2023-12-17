#include <iostream>
using namespace std;

int arr[301];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 3; i <= n; i++) {
		if (arr[i - 2] && arr[i - 1] && arr[i]) {
			if (arr[i - 1] <= arr[i]) {
				int mincnt = min(arr[i - 2], min(arr[i - 1], arr[i]));
				ans += mincnt * 7;
				arr[i - 2] -= mincnt;
				arr[i - 1] -= mincnt;
				arr[i] -= mincnt;
				mincnt = min(arr[i - 2], arr[i - 1]);
				ans += mincnt * 5;
				arr[i - 2] -= mincnt;
				arr[i - 1] -= mincnt;

			}
			else {
				int mincnt = min(arr[i - 2],arr[i-1]-arr[i]);
				ans += mincnt * 5;
				arr[i - 2] -= mincnt;
				arr[i - 1] -= mincnt;
				mincnt = min(arr[i - 2], min(arr[i - 1], arr[i]));
				ans += mincnt * 7;
				arr[i - 2] -= mincnt;
				arr[i - 1] -= mincnt;
				arr[i] -= mincnt;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (arr[i - 1] && arr[i]) {
			int mincnt = min(arr[i - 1], arr[i]);
			ans += mincnt * 5;
			arr[i - 1] -= mincnt;
			arr[i] -= mincnt;
		}

	}
	for (int i = 1; i <= n; i++) {
		if (arr[i]) {
			ans += arr[i] * 3;
		}

	}
	


	cout << ans;



}