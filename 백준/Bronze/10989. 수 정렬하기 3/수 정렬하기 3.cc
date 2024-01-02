#include <iostream>
#include <algorithm>
using namespace std; 
int arr[10001];
int main() {
	
	int n;
	cin >> n;
	int x;

	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		arr[x]++;
	}
	for (int i = 1; i <= 10000; i++) {
		if (arr[i] != 0) {
			for (int j = 0; j < arr[i]; j++) {
				cout << i << '\n';
			}
		}
	}
}