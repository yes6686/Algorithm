#include <iostream>
using namespace std;

int arr[100001];
int s[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i == 0) s[i] = arr[i];
		else {
			s[i] = s[i - 1] + arr[i];
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a - 2 >= 0) {
			cout << s[b - 1] - s[a - 2] << '\n';
		}
		else {
			cout << s[b - 1] << '\n';
		}
	}
}