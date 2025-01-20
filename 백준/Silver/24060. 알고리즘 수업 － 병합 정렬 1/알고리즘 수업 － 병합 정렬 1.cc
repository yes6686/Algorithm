#include <iostream>
using namespace std;

int arr[500001];
int tmp[500001];
int cnt = 0;
int n, k;
int ans = -1;

void merge(int p, int q, int r) {
	int i = p;
	int j = q + 1;
	int t = 0;
	while (i <= q && j <= r) {
		if (arr[i] <= arr[j]) {
			tmp[t++] = arr[i++];
		}
		else {
			tmp[t++] = arr[j++];
		}
	}
	while (i <= q) {
		tmp[t++] = arr[i++];
	}
	while (j <= r) {
		tmp[t++] = arr[j++];
	}

	i = p;
	t = 0;
	while (i <= r) {
		cnt++;
		if (cnt == k) {
			ans = tmp[t];
		}
		arr[i++] = tmp[t++];
	}
}

void merge_sort(int p,int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(p, q);
		merge_sort(q+1, r);
		merge(p, q, r);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	merge_sort(0, n-1);

	cout << ans << '\n';
}