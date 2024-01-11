#include <iostream>
#include <queue>
#include <cmath>
using namespace std;




struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) return a > b;
		return  abs(a) > abs(b);
	}

	
};

priority_queue<int, vector<int>, cmp >pq;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	int x;
	while (T--) {
		cin >> x;
		if (x == 0) {
			if (pq.size() == 0) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}



}