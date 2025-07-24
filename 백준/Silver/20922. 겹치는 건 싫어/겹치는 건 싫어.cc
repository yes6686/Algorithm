#include <iostream>
using namespace std;

int arr[200001];
int cnt[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	int left = 0;
	int right = 1;

	int maxLength = 1;
	cnt[arr[left]]++;

	while (right < n) {

		if (cnt[arr[right]] + 1 > k) {
			cnt[arr[left]]--;
			left++;
		}
		else {
			cnt[arr[right]]++;
			right++;
			maxLength = max(maxLength, right - left);
		}
	}
	cout << maxLength << '\n';
}