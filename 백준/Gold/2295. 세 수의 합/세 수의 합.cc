#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1001];

vector<int>v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v.push_back(arr[i] + arr[j]);
		}
	}
	sort(arr, arr + n);
	sort(v.begin(), v.end());

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			int k = arr[i] - arr[j];
			bool check=	binary_search(v.begin(), v.end(), k);
			if (check) {
				cout << arr[i] << '\n';
				return 0;
			}
		}
	}
}