#include <iostream>
using namespace std;

int arrA[11];
int arrB[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int lastWinner = 0;
	int aCnt = 0;
	int bCnt = 0;


	for (int i = 0;i < 10;i++) {
		cin >> arrA[i];
	}

	for (int i = 0;i < 10;i++) {
		cin >> arrB[i];
	}

	for (int i = 0;i < 10;i++) {
		if (arrA[i] > arrB[i]) {
			aCnt += 3;
			lastWinner = 1;
		}
		else if (arrA[i] < arrB[i]) {
			bCnt += 3;
			lastWinner = 2;
		}
		else {
			aCnt += 1;
			bCnt += 1;
		}
	}

	cout << aCnt << " " << bCnt << '\n';
	if (aCnt > bCnt) {
		cout << "A" << '\n';
	}
	else if (aCnt < bCnt) {

		cout << "B" << '\n';
	}
	else {
		if (lastWinner == 0) {
			cout << "D" << '\n';
		}
		else if (lastWinner == 1) {
			cout << "A" << '\n';
		}
		else {
			cout << "B" << '\n';
		}
	}
}