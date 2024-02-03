#include <iostream>
using namespace std;


int a[10001];
int b[10001];
int main() {
	int d, k;
	cin >> d >> k;
	a[1] = 1;
	b[2] = 1;
	for (int i = 3; i <= d; i++) {
		a[i] = a[i - 1] + a[i - 2];
		b[i] = b[i - 1] + b[i - 2];
	}
	int check = 0;
	for (int i = 1; i <= k; i++) {
		if (check == 1) {
			break;
		}
		for (int j = 1; j <= k; j++) {
			if (a[d] * i + b[d] * j == k) {
				cout << i << '\n' << j<<endl;
				check = 1;
				break;
			}
		}
	}
	

}