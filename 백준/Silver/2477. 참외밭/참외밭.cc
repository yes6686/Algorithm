#include <iostream>
#include <queue>
using namespace std;

queue<int>q;
queue<int>qq;

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
	int di = 1;
	while (!q.empty()) {
		int currV = q.front();
		q.pop();
		if ((preV == maxW && currV == maxH) ||
			(preV == maxH && currV == maxW)) {
			q.pop();
			for (int i = 0; i < 2; i++) {
				di *= q.front();
				q.pop();
			}
			break;
		}
		preV = currV;
	}
	cout << k * (maxH * maxW - di);
}