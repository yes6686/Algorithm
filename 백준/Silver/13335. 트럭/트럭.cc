#include <iostream>
#include <queue>
using namespace std;

queue<int>q1;
queue<int>q2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, w, l;
	cin >> n >> w >> l;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q1.push(x);
	}
	int currW = 0;
	int ansT = 0;
	while (!q1.empty()) {
		int x = q1.front();
		if (q2.size() == w) {
			currW -= q2.front();
			q2.pop();
		}

		if (currW + x <= l) {
			currW += x;
			q1.pop();
			q2.push(x);
			ansT++;
		}
		else {
			ansT++;
			q2.push(0);
		}
	}
	cout << ansT + w;
}
