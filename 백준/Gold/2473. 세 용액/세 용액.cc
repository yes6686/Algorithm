#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long int arr[100001];
long long int resultArr[3];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	long long int result = 3e9+1;
	
	for (int i = 0; i < n-2; i++) {
		int k = i + 1;
		int w = n - 1;
		while (k<w) {

			long long int sum = arr[i] + arr[k] + arr[w];
			if (result > abs(sum)) {
				result = abs(sum);
				resultArr[0] = arr[i];
				resultArr[1] = arr[k];
				resultArr[2] = arr[w];
				
			}
			if (sum < 0) {
				k++;
			}
			else {
				w--;
			}
		//	if (k == w) break;
		}
	}

	for (int i = 0; i < 3; i++) {
		cout << resultArr[i] << ' ';
	}
}