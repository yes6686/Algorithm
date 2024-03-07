#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int,vector<int>,less<int>>pq;

int main() {
	int T;
	cin >> T;
	while (T--) {
		while (1) {
			int x;
			cin >> x;
			if (x == 0) break;
			pq.push(x);
		}
		int sum = 0;
		int r = 1;
		int check = 0;
		while (!pq.empty()) {
			int k = pq.top();
			pq.pop();	
			sum += 2 *pow(k, r);
			if (sum > 5 * 1000000) {
				check = 1;
				continue;
			}
			r += 1;
		}
		if (check == 1) {
			cout << "Too expensive" << '\n';
		}else{
			cout << sum << '\n';
		}
	}
}