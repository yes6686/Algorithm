#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	long long n, num;
	vector<long long> v;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < n; i++) {
		cout << v.at(i) << "\n";
	}
	return 0;
}