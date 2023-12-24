#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[1001];
int inDegree[1001];
vector<int>v[1001];
queue<int>q;
queue<int>result;
int main() {
	int n, m;
	cin >> n >> m;
	int w;
	//int x;
	for (int i = 0; i < m; i++) {
		cin >> w;
		for (int j = 0; j < w; j++) {
			cin >> arr[j];
		}
		for (int j = 1; j < w; j++) {
			v[arr[j - 1]].push_back(arr[j]);
			inDegree[arr[j]]++;
		}

	}
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}
	for(int i=1;i<=n;i++){
		if (q.empty()) {
			cout << 0 << endl;
			return 0;
		}


		int k = q.front();
		q.pop();
		result.push(k);
		for (int i = 0; i < v[k].size(); i++) {
			int j = v[k][i];
			inDegree[j]--;
			if (inDegree[j] == 0) q.push(j);
		}
	}
	while (!result.empty()) {
		int k = result.front();
		result.pop();
		cout << k << '\n';
	}
}