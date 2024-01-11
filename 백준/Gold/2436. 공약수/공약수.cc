#include <iostream>
#include <algorithm>
using namespace std;


int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int lcm(long long int a,long long int b) {
	return (a * b) / gcd(a, b);
}

int arr[100001];

int main() {
	
	int a, b;
	cin >> a >> b;
	int s = 0;
	for (int i = 1; i * i <= b; i++) {
		if (b % i == 0) {
			arr[s++] = i;
			arr[s++] = b / i;
		}
	}
	sort(arr, arr + s);
	int firstNum = 100000001;
	int secondNum = 100000001;
	for (int i = 0; i < s; i++) {
		if (arr[i] % a != 0) continue;
		for (int j = i; j < s; j++) {
			if (gcd(arr[i], arr[j]) == a && lcm(arr[i], arr[j]) == b) {
				if (firstNum + secondNum > arr[i] + arr[j]) {
					firstNum = arr[i];
					secondNum = arr[j];
				}
			}
		}
	}
	cout << firstNum << ' ' << secondNum;
}