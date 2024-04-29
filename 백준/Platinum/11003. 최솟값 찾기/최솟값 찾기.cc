#include <iostream>
#include <deque>
using namespace std;

int arr[5000001];

deque<pair<int,int>>d;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l;
	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		
		while (!d.empty()) {
			if (d.back().first > arr[i]) {
				d.pop_back();
			}
			else {
				break;
			}
		}
		d.push_back({ arr[i],i});
		
		if (d.front().second <= i - l) {
			d.pop_front();
		}
		cout << d.front().first << ' ';
	}
}