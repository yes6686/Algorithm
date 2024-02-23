#include <iostream>
using namespace std;

int arr[12];
int opCnt[5];
int n;

int maxAns = -1e9;
int minAns = 1e9;


void solve(int d,int r) {
	if (d >= n) {
		maxAns = max(maxAns, r);
		minAns = min(minAns, r);
		return;
	}
	for (int i = 1; i <= 4; i++) {
		if (opCnt[i] > 0) {
			opCnt[i]--;
			if (i == 1) { // (+)
				solve(d + 1, r + arr[d]);
			}
			else if (i == 2) { // (-)
				solve(d + 1, r - arr[d]);
			}
			else if (i == 3) { // (*)
				solve(d + 1, r * arr[d]);
			}
			else { // (/)
				solve(d + 1, r / arr[d]);
			}
			opCnt[i]++;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= 4; i++) { // 1 : (+) , 2 : (-) , 3 : (x) , 4 : (/)
		cin >> opCnt[i];
	}
	solve(1, arr[0]);
	cout << maxAns << '\n' << minAns;
}