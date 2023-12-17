#include <iostream>
using namespace std;

long long int arr[1000001];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int b, c;
	cin >> b >> c;
	long long int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	if (b <= c) {
		for(int i=1;i<=n;i++)
		ans += arr[i]*b;
	}
	else {



		for (int i = 3; i <= n; i++) {
			if (arr[i - 2] && arr[i - 1] && arr[i]) {
				if (arr[i - 1] <= arr[i]) {
					long long int mincnt = min(arr[i - 2], min(arr[i - 1], arr[i]));
					ans += mincnt * (b + 2 * c);
					arr[i - 2] -= mincnt;
					arr[i - 1] -= mincnt;
					arr[i] -= mincnt;
					mincnt = min(arr[i - 2], arr[i - 1]);
					ans += mincnt * (b + c);
					arr[i - 2] -= mincnt;
					arr[i - 1] -= mincnt;

				}
				else {
					long long int mincnt = min(arr[i - 2], arr[i - 1] - arr[i]);
					ans += mincnt * (b + c);
					arr[i - 2] -= mincnt;
					arr[i - 1] -= mincnt;
					mincnt = min(arr[i - 2], min(arr[i - 1], arr[i]));
					ans += mincnt * (b + c * 2);
					arr[i - 2] -= mincnt;
					arr[i - 1] -= mincnt;
					arr[i] -= mincnt;
				}
			}
		}
		for (int i = 2; i <= n; i++) {
			if (arr[i - 1] && arr[i]) {
				long long int mincnt = min(arr[i - 1], arr[i]);
				ans += mincnt * (b + c);
				arr[i - 1] -= mincnt;
				arr[i] -= mincnt;
			}

		}
		for (int i = 1; i <= n; i++) {
			if (arr[i]) {
				ans += arr[i] * b;
			}

		}
	}
		cout << ans;
}