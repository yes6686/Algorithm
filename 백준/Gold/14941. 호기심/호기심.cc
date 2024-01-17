#include <iostream>
using namespace std;

int arr[100001];
int arr1[100001];
int arr2[100001];
int sum1[100001];
int sum2[100001];
int nArr[100001];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	for (int i = 2; i < 100001; i++)arr[i] = i;

	for (int i = 2; i * i < 100001; i++) {
		if (!arr[i]) continue;
		for (int j = i * i; j < 100001; j+=i) {
			arr[j] = 0;
		}
	}
	int check = 1;
	for (int i = 1; i < 100001; i++) {
		if (arr[i]) {
			if (check) {
				check = 0;
				sum1[i] = 3 * arr[i] + sum1[i - 1];
				arr1[i] = 3 * arr[i];
				sum2[i] = sum2[i - 1] - arr[i];
				arr2[i] = arr[i] * (-1);
			}
			else {
				check = 1;
				sum1[i] = sum1[i - 1] - arr[i];
				arr1[i] = arr[i] * (-1);
				sum2[i] = 3 * arr[i] + sum2[i - 1];
				arr2[i] = 3 * arr[i];
			}
		}
		else {
			sum1[i] = sum1[i - 1];
			sum2[i] = sum2[i - 1];
		}
	}
	int a, b;
	int ans;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		int firstP=0;
		for (int j = a; j <= b; j++) {
			if (arr[j]) {
				firstP = j;
				break;
			}
		}
		if (firstP == 0) {
			cout << 0 << '\n';
		}
		else {
			if (arr1[firstP]>0) {
				cout << sum1[b] - sum1[a-1]<<'\n';
			}
			else {
				cout << sum2[b] - sum2[a-1] << '\n';
			}
		}
	}
}