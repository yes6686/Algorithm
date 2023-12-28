#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[10001];
int t[10001];
int indegree[10001];
vector<int>v[10001];
queue<int>q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int result = -1;
	int n;
	cin >> n;
	int m;
	int x;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (result < arr[i]) {
			result = arr[i];
		}
		t[i] = arr[i];
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> x;
			v[x].push_back(i);
			indegree[i]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		int k = q.front();
		q.pop();
		for (int i = 0; i < v[k].size(); i++) {
			int j = v[k][i];
			indegree[j]--;
			t[j] = max(t[j], arr[j] + t[k]);
			if (result < t[j]) {
				result = t[j];
			}
			if (indegree[j] == 0) {
				q.push(j);
			}
		}
	}
	cout << result;
	

}