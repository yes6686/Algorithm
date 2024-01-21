#include <iostream>
using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int isAllNegative = 1;
	int maxAns = -1001;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > 0) isAllNegative = 0; // 원소 중 양수가 있나 체크
		if (maxAns < arr[i]) {
			maxAns = arr[i];
		}
	}
	if (isAllNegative == 1) {
		cout << maxAns << '\n';
		return 0;
	}
	int sumGoing = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] <0) {
			maxAns = max(maxAns, sumGoing);
		}
		sumGoing += arr[i];
		if (sumGoing < 0) {
			sumGoing = 0;
		}
		maxAns = max(maxAns, sumGoing);
	}
	cout << maxAns;
}