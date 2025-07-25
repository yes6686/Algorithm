#include <iostream>
#include <vector>
using namespace std;

int arr[11];

vector<int>v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
	}

	v.push_back(n);
	for (int i = n-1;i >= 1;i--) {
		v.insert(v.begin() + arr[i], i);
	}

	for (int i = 0;i < v.size();i++) {
		cout << v[i] << " ";
	}
}