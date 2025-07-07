#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

deque<int>d;

int arr[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	
	int zeroCnt = 0;
	int nCnt = 0;
	int pCnt = 0;
	sort(arr, arr + n);

	for (int i = 0;i < n;i++) {
		if (arr[i] == 0) {
			zeroCnt++;
		}
		else if (arr[i] > 0) {
			pCnt++;
			d.push_back(arr[i]);
		}
		else {
			nCnt++;
			d.push_back(arr[i]);
		}
	}

	int ans = 0;
	while (!d.empty()) {
		if (pCnt >= 2) {
			int a = d.back();
			d.pop_back();
			int b = d.back();
			d.pop_back();
			if (a == 1 || b == 1) {
				ans += (a + b);
			}
			else {
				ans += (a * b);
			}
			pCnt -= 2;
		}
		else if (pCnt >= 1) {
			int a = d.back();
			d.pop_back();
			ans += a;
			pCnt -= 1;
		}
		if (nCnt >= 2) {
			int a = d.front();
			d.pop_front();
			int b = d.front();
			d.pop_front();
			ans += (a * b);
			nCnt -= 2;
		}
		else if (nCnt >= 1) {
			int a = d.front();
			d.pop_front();
			if (zeroCnt == 0) {
				ans += a;
			}
			else {
				zeroCnt--;
			}
			nCnt -= 1;
		}		
	}
	cout << ans << '\n';
}