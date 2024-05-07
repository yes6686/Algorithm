#include <iostream>
using namespace std;

int pr[10000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 2; i <= 10000000; i++) {
		pr[i] = i;
	}

	for (int i = 2; i * i <= 10000000; i++) {
		if (pr[i] == 0) continue;
		for (int j = i * i; j <= 10000000; j += i) {
			pr[j] = 0;
		}
	}

	long long int a, b;
	cin >> a >> b;
	int cnt = 0;
	for (long long int i = 2; i*i <= b; i++) {
		if (pr[i] == 0) continue;
		for (long long int j = i * i; j <= b; j *= i) {
			if (j % i != 0)break;
			if (j >= a) cnt++;
		}
	}
	cout << cnt;
}