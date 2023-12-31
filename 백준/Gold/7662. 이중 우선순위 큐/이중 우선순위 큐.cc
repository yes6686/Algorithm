#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

priority_queue<int,vector<int>,less<int>>pq1; //내림차순
priority_queue<int,vector<int>,greater<int>>pq2; // 오름차순
map<string,int>mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int k;
		cin >> k;
		char c;
		int n;
		int count = 0;
		for (int i = 0; i < k; i++) {
			cin >> c >> n;
			if (c == 'I') {
				pq1.push(n);
				pq2.push(n);
				mp[to_string(n)]++;
				count++;
			}
			else if(c=='D') {
				if (n == 1) {
					if (pq1.size() == 0) continue;
					while (!pq1.empty()) {
						if (mp[to_string(pq1.top())]) {
							mp[to_string(pq1.top())]--;
							pq1.pop();
							break;
						}
						else {
							pq1.pop();
						}
					}
				}
				else if (n == -1) {
					if (pq2.size() == 0) continue;
					while (!pq2.empty()) {
						if (mp[to_string(pq2.top())]) {
							mp[to_string(pq2.top())]--;
							pq2.pop();
							break;
						}
						else {
							pq2.pop();
						}
					}
				}
				count--;
				if (count == 0) {
					while (!pq1.empty()) pq1.pop();
					while (!pq2.empty()) pq2.pop();
				}
			}
		}
		if (count == 0) {
			cout << "EMPTY" << '\n';
		}
		else {
			int last=0;
			while (!pq1.empty()) {
				if (mp[to_string(pq1.top())]) {
					mp[to_string(pq1.top())]--;
					if (last == 0) {
						cout << pq1.top() << ' ';
						last = pq1.top();
					}
					else {
						last = pq1.top();
					}
				}
				pq1.pop();
			}
			while (!pq2.empty()) {
				if (mp[to_string(pq2.top())]) {
					mp[to_string(pq2.top())]--;
					if (last == 0) {
						cout << pq2.top() << ' ';
						last = pq2.top();
					}
					else {
						last = pq2.top();
					}
				}
				pq2.pop();
			}
			cout << last << '\n';
		}
		while (!pq1.empty()) pq1.pop();
		while (!pq2.empty()) pq2.pop();
		mp.clear();
	}
}