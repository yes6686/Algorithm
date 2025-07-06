#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int>v[51];
int visited[51];
int arr3[2];
int arr4[2];

void dfs(int x) {
	for (int i = 0;i < v[x].size();i++) {
		int k = v[x][i];
		if (visited[k]) continue;
		visited[k] = 1;
		if (v[k].size() == 2) {
			dfs(k);
		}
		else if (v[k].size() == 3) {
			if (arr3[0] == 0) arr3[0] = k;
			else arr3[1] = k;
		}
		else if (v[k].size() == 4) {
			if (arr4[0] == 0) {
				arr4[0] = k;
				dfs(k);
			}
			else {
				arr4[1] = k;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0;i < n + 3;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int s;
	for (int i = 1;i <= n;i++) {
		if (v[i].size() == 1) {
			s = i;
		}	
	}
	visited[s] = 1;
	dfs(s);
	for (int i = 1;i <= n;i++) {
		if (v[i].size() == 3 && visited[i] == 0) {
			cout << i << " ";
		}
	}
	sort(arr3, arr3 + 2);
	cout << arr3[0] << " " << arr4[1] << " " << arr3[1] << " " << arr4[0] << " " << s << '\n';
}