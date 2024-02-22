#include <iostream>
using namespace std;
int arr[51];
int main() {
	int n, s, p;
	cin >> n >> s >> p;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int cnt = 1;
	int rank = 1;
	for (int i = 0; i < n; i++) {
		if (arr[i] < s) break;	
		if (arr[i] > s) {
			rank++;
		}
		cnt++;
	}
	if (cnt <= p) cout << rank;
	else
		cout << -1;
}