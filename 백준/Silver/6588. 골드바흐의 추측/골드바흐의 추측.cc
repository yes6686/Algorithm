#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

int arr[1000001];

vector<int>v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	for (int i = 2; i < MAX; i++) {
		arr[i] = i;
	}

	for (int i = 2; i*i < MAX; i++) {
		if (arr[i]==0) continue;
		for (int j = i * i; j < MAX; j += i) {
			arr[j] = 0;
		}
	}


	for (int i = 2; i < MAX; i++) {
		if (arr[i]) v.push_back(arr[i]);
	}


	while (true) {
		int n;
		cin >> n;
		if (!n) break;
		int check = 0;
		
		for (int i = 0; i < v.size(); i++) {
			if (arr[n - v[i]]) {
				check = 1;
				cout << n << " = " << v[i] << " + " << n - v[i] << '\n';
				break;
			}
		}

		if (check == 0) {
			cout << "Goldbach's conjecture is wrong." << '\n';
		}

	}
}