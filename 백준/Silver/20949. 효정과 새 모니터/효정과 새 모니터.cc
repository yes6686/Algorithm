#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int>arr[1001];

bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) {
		return a < b;
	}
	return a > b;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[i].first = a * a + b * b;
		arr[i].second = i + 1;
	}
	sort(arr, arr + n,compare);

	for (int i = 0; i < n; i++) {
		cout << arr[i].second << '\n';
	}
}