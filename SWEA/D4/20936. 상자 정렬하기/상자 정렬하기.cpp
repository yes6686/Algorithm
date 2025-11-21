#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int arr[501];
int visited[501];
int loc[501];
int ch[501];
vector<int>v;

void dfs(int x) {
	if (ch[loc[x]] == 1) return;
	
	ch[loc[x]] = 1;
	v.push_back(loc[x]);
	dfs(loc[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0;i < n;i++) {
			cin >> arr[i];
			loc[arr[i]] = i + 1;
		}
		for (int i = 0;i < n;i++) {
			if (arr[i] != i + 1 && ch[i + 1] == 0) {
				ch[i + 1] = 1;
				v.push_back(i + 1);
				dfs(i + 1);
				v.push_back(n + 1);
			}
		}

		cout << v.size() << "\n";
		for (int i = 0;i < v.size();i++) {
			cout << v[i] << " ";
		}
		cout << '\n';


		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));
		memset(loc, 0, sizeof(loc));
		memset(ch, 0, sizeof(ch));
		v.clear();
	}
}