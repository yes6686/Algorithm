#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];
int s[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		
	}
	int m;
	cin >> m;
	sort(arr, arr + n+1); 
	for (int i = 1; i <= n; i++) {
		s[i] = arr[i] + s[i - 1];
	}
	int ans;
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] + ((n - i + 1) * arr[i]) > m) {
			for (int j = arr[i - 1] + 1; j < arr[i]; j++) {
				if (s[i - 1] + ((n - i + 1) * j) > m) {
					break;
				}
				else {
					ans = j;
				}
			}
			break;
		}
		else {
			ans = arr[i];
		}
	}
	cout << ans;
}