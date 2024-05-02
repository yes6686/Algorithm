#include <iostream>
using namespace std;

int arr[51];
int cnt[51];

int checkLineMeetF(double a1, double b1, double a2, double b2, double x,double y) {
	double m= (b1 - b2) / (a1 - a2);
	double b = b1 - m * a1;

	if (m * x + b - y > 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			int check = 1;
			for (int t = i + 1; t < j; t++) {
				if (checkLineMeetF(i, arr[i], j, arr[j], t, arr[t]) == 0) {
					check = 0;
					break;
				}
			}
			if (check == 1) {
				cnt[i]++;
				cnt[j]++;
			}
		}
	}
	int maxAns = 0;
	for (int i = 1; i <= n; i++) {
		maxAns = max(maxAns, cnt[i]);
	}
	cout << maxAns;
}