#include <iostream>
#include <vector>
using namespace std;


int main() {
	vector<int >v;
	int n,x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) {
			v.pop_back();
		}
		else {
			v.push_back(x);
		}
	}
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}
	cout << sum;

}