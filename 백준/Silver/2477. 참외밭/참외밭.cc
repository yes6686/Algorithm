#include <iostream>
#include <queue>
using namespace std;

queue<int>q;
queue<int>qq;
queue<int>q1;
queue<int>q2;

int main() {
	int k;
	cin >> k;
	int maxH = 0;
	int maxW = 0;
	int c;
	int dis;

	for (int i = 0; i < 6; i++) {
		cin >> c >> dis;
		q.push(dis);
		qq.push(dis);
		if (c == 1 || c == 2) {
			maxW = max(maxW, dis);
		}
		else {
			maxH = max(maxH, dis);
		}
	}
	while (!qq.empty()) {
		int k = qq.front();
		qq.pop();
		q.push(k);
	}
	int preV = q.front();
	q.pop();
	int check = 0;
	while (!q.empty()) {
		int currV = q.front();
		q.pop();
		if ((preV == maxW && currV == maxH) ||
			(preV == maxH && currV == maxW)) {
			while (!q.empty()) {
				currV = q.front();
				q2.push(currV);
				q.pop();
			}
			break;
		}
		q1.push(preV);
		preV = currV;
	}
	int ans = 1;
	int cnt = 0;
	int multcheck = 0;
	while (!q2.empty()) {
		int k = q2.front();
		q2.pop();
		if (cnt == 1 || cnt == 2) {
			ans *= k;
		}
		cnt++;
	}
	while (!q1.empty()) {
		int k = q1.front();
		q1.pop();
		if (cnt == 1 || cnt == 2) {
			ans *= k;
		}
		cnt++;
	}
	ans = maxH * maxW - ans;
	ans *= k;
	cout << ans;
}