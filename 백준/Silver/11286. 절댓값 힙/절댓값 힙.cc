#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

priority_queue<int,vector<int>,greater<int>>pq1;
priority_queue<int,vector<int>,less<int>>pq2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		if (x == 0) {

			if (pq1.size() == 0 && pq2.size() == 0) {
				cout << 0 << '\n';
			}
			else if (pq1.size() == 0 && pq2.size()>0) {
				cout << pq2.top() << '\n';
				pq2.pop();
			}
			else if (pq2.size() == 0 && pq1.size() > 0){
				cout << pq1.top() << '\n';
				pq1.pop();
			}

			else if (abs(pq1.top()) >= abs(pq2.top())) {
				cout << pq2.top() << '\n';
				pq2.pop();
			}
			else {
				cout << pq1.top() << '\n';
				pq1.pop();
			}
		}
		else {
			if (x > 0) {
				pq1.push(x);
			}
			else {
				pq2.push(x);
			}
		}
	}
}