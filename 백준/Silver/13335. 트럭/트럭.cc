#include <iostream>
using namespace std;

int arr[1001];
int larr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, w, l;
	cin >> n >> w >> l;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int t = 0;
	int s = 0;

	while (true) {
		int sum = 0;
		int currLengthW = 0; // 현재 다리 위에 차 무게의 합 
		for (int i = s; i < n; i++) {
			if (currLengthW + arr[i] > l) {
				break;
			}
			currLengthW += arr[i];
			if (i == s) {
				larr[i]++;
			}
			else {
				if (larr[i - 1] - larr[i] >= 2) {
					larr[i]++;
				}
				else {
					break;
				}
			}
			if (larr[i] > w) {
				s++;
				currLengthW -= arr[i];
			}
		}
		t++;
		if (s == n) break;

	}
	cout << t << '\n';
}