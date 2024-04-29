#include <iostream>
#include <deque>
using namespace std;

int arr[1000001];

deque<pair<int,int>>dmin;
deque<pair<int,int>>dmax;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l,c;
	cin >> n >> l>>c;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int check = 0;
	for (int i = 1; i <= n; i++) {
		while (!dmin.empty()) {
			if (dmin.back().first >= arr[i]) {
				dmin.pop_back();
			}
			else {
				break;
			}
		}
		dmin.push_back({ arr[i],i});

		while (!dmax.empty()) {
			if (dmax.back().first <= arr[i]) {
				dmax.pop_back();
			}
			else {
				break;
			}
		}
		dmax.push_back({ arr[i],i });
		
		if (dmin.front().second <= i - l) {
			dmin.pop_front();
		} 
		if (dmax.front().second <= i - l) {
			dmax.pop_front();
		}
		if ( i-l+1>0) {
			if (dmax.front().first - dmin.front().first <= c) {
				cout << i - l + 1 << '\n';
				check = 1;
			}
		}
	}
	if (check == 0) cout << "NONE";
}