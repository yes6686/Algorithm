#include <iostream>
using namespace std;

int arr[60001];
int cnt[3001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, d, k, c;
	cin >> n >> d >> k >> c;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
		arr[n + i] = arr[i];
	}

	int maxAns = 1;
	cnt[c]++;
	int g = 1;
	for (int i = 0;i < k;i++) {
		if (cnt[arr[i]] == 0) {
			g++;
			maxAns = max(maxAns, g);
		}
		cnt[arr[i]]++;
	}

	for (int i = k;i < n*2;i++) {
		cnt[arr[i - k]]--; 
		if (cnt[arr[i - k]] == 0) g--;
		cnt[arr[i]]++;
		if (cnt[arr[i]] == 1) g++;
		maxAns = max(maxAns, g);
	}

	cout << maxAns;
}