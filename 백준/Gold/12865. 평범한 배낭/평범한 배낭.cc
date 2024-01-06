#include <iostream>
#include <queue>
using namespace std;
int arr[100001];
int main() {
	int n, k;
	int w, v;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w >> v;	
		for (int j = k-1; j >=1; j--) {
			if (arr[j]!=0 && j+w<=k) {
				arr[j + w] = max(arr[j+w], arr[j] + v);
			}
		}
		arr[w] = max(arr[w], v);
	}
	int max = -1;
	for (int i = 1; i <= k; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	cout << max;
}