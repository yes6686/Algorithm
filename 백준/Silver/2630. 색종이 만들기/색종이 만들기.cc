#include <iostream>
using namespace std;

int arr[130][130];
int whitePaper = 0;
int bluePaper = 0;

void recur(int a1,int b1,int a2,int b2,int x) {
	int sum = 0;
	for (int i = a1; i <= a2; i++) {
		for (int j = b1; j <= b2; j++) {
			sum += arr[i][j];
		}
	}
	if (sum == x * x) {
		bluePaper++;
		return;
	}
	else if (sum == 0) {
		whitePaper++;
		return;
	}
	else {
		recur(a1, b1, a2 - x / 2, b2 - x / 2,x/2);
		recur(a1, b1+x/2, a2 - x / 2, b2,x/2);
		recur(a1+x/2, b1, a2, b2 - x / 2,x/2);
		recur(a1+x/2, b1+x/2, a2, b2,x/2);
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	recur(1, 1, n, n, n);
	cout << whitePaper << endl;
	cout << bluePaper << endl;
	

	

}