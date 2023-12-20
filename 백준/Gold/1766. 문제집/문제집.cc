#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int>v[32001];
int indegree[32001];
priority_queue<int, vector<int>,greater<int>>q;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n>>m;
	int a, b;



	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}
	if (n == 1) {
		cout << 1 << endl;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0) q.push(i);
		}


		for (int i = 1; i <= n; i++) {
			int k = q.top();
			q.pop();
			cout << k << ' ';
			for (int j = 0; j < v[k].size(); j++) {
				int h = v[k][j];
				indegree[h]--;
				if (indegree[h] == 0) {
					q.push(h);
				}
			}
		}
	}
	
	

}