#include <iostream>
using namespace std;

int arr[13];

int main() {
	int k;
	cin >> k;
	int maxH = 0;
	int maxW = 0;
	int c;
	int dis;

	for (int i = 0; i < 6; i++) {
		cin >> c >> dis;
		arr[i] = dis;
		arr[i+6] = dis;
		if (c == 1 || c == 2) {
			maxW = max(maxW, dis);
		}
		else {
			maxH = max(maxH, dis);
		}
	}
	int preV = arr[0];
	int check = 0;
	int di = 1;
	int cnt = 0;
	for (int i = 1; i < 12; i++) {
		int curV;
		curV = arr[i];
		if (check) {
			if (cnt) {
				di *= curV;
			}
			cnt++;
		}
		if ((preV == maxW && curV == maxH) || (preV == maxH && curV == maxW)) {
			check = 1;
		}
		if (cnt == 3) break;
		preV = curV;
	}
	cout << k * (maxH * maxW - di);
	
}