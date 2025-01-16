#include <iostream>
#include <deque>
using namespace std;

deque<int>d;

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (arr[i] == 0) {
			d.push_back(x);
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		d.push_front(x);
		cout << d.back() << ' ';
		d.pop_back();
	}
}