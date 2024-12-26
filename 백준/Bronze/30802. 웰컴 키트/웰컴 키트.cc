#include <iostream>
using namespace std;

int arr[6];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < 6; i++) {
		cin >> arr[i];
	}
	int t, p;
	cin >> t >> p;

	int minT = 0;
	int maxP = n / p;
	int pp = n % p;

	for (int i = 0; i < 6; i++) {
		minT = (arr[i] % t==0) ? minT+arr[i]/t : minT+(arr[i]/t)+1;
	}
	cout << minT << '\n' << maxP << ' ' << pp << '\n';
}