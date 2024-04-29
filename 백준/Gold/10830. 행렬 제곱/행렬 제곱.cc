#include <iostream>
#include <string.h>
using namespace std;

int arr[6][6];
int a[6][6]; // 단위행렬
int n;
long long int b;

void mc(int a1[6][6], int a2[6][6]) {
	int a3[6][6];
	memset(a3, 0, sizeof(a3));
	for (int t = 0; t < n; t++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a3[i][t] += (a1[i][j] * a2[j][t]);
			}
			a3[i][t] %= 1000;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a1[i][j] = a3[i][j];
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
		a[i][i] = 1;
	}

	
	while (b>1) {
		if (b % 2 == 1) {
			mc(a, arr);
			
		}
		mc(arr, arr);	
		b /= 2;
	}
	mc(arr, a);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}

}