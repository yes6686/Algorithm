#include <iostream>
using namespace std;
int arr[101];
int main() {
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		int k = 0;
		for (int j = x; j <= x+((y-x+1)/2)-1; j++) {
			int temp = arr[j];
			arr[j] = arr[y - k];
			arr[y-k] = temp;
			k++;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << ' ';
	}
}